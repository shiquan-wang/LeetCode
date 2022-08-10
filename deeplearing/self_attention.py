import math
from platform import node
from time import clock_getres
from turtle import forward

from torch import Tensor, dropout, softmax
import numpy as np
import torch
import torch.functional as F
import torch.nn as nn

class SelfAttention(nn.Module):
    def __init__(self, d_model, dim_k, dim_v, n_heads) -> None:
        super(SelfAttention, self).__init__()
        self.dim_v = dim_v
        self.dim_k = dim_k
        self.n_heads = n_heads

        self.q = nn.Linear(d_model, dim_k)
        self.k = nn.Linear(d_model, dim_k)
        self.v = nn.Linear(d_model, dim_v)

        self.o = nn.Linear(dim_v, d_model)
        self.norm_fact = 1 / math.sqrt(d_model)

    def forward(self, x, y, requires_mask=False):
        assert self.dim_k % self.n_heads == 0 and self.dim_v % self.n_heads == 0
        #size of x [batch_size * seq_len * d_model]
        Q = self.q(x)#self_attention [batch_size, seq_len, dim_k]
        Q = Q.reshape(-1, x.shape[0], x.shape[1], self.dim_k // self.n_heads)#multi head, [n_heads, batch_size, seq_len, dim_k]


class MultiHeadAttention(nn.Module):
    def __init__(self, heads, d_model, dropout = 0.1):
        super().__init__()
        assert d_model % heads == 0#确认模型维数可以整除head数目

        self.d_k = d_model // heads
        self.heads = heads
        # self.linears = clones(nn.Linear(d_model, d_model), 4)
        self.q = nn.Linear(d_model, d_model)
        self.k = nn.Linear(d_model, d_model)
        self.v = nn.Linear(d_model, d_model)
        self.o = nn.Linear(d_model, d_model)
        self.attn = None
        self.dropout = nn.Dropout(p = dropout)
    
    def forward(self, query : Tensor, key : Tensor, value : Tensor, mask=None):
        if mask is not None:
            mask = mask.unsqueeze(1)
        
        batch_size = query.shape[0]
        #step 1, 线性变换，改变维度, [batch_size, seq_len, d_model=512] -> [batch_size, n_heads=8, seq_len, d_k=64]
        query = self.q(query)#[batch_size, seq_len, d_model=512]
        query = query.reshape(batch_size, -1, self.heads, self.d_k)#[batch_size, seq_len, n_heads=8, d_k=64]
        query = query.permute(0, 2, 1, 3)#[batch_size, h_heads=8, seq_len, d_k=64]
        key = self.k(key)
        key = key.reshape(batch_size, -1, self.heads, self.d_k).permute(0, 2, 1, 3)
        value = self.v(value)
        value = value.reshape(batch_size, -1, self.heads, self.d_k).permute(0, 2, 1, 3)

        #step2, attention运算
        x, self.attn = self.attention(query, key, value, mask=mask, dropout=self.dropout)

        #step3, concat,
        x = x.permute(0, 2, 1, 3).reshape(batch_size, -1, self.d_k*self.heads)#x [batch_size, n_heads=8, seq_len, d_k] -> [batch_size, seq_len, d_model=512=8*64]
        return self.o(x)

    def attention(self, query:Tensor, key:Tensor, value:Tensor, mask=None, dropout=None):
        d_k = query.shape[-1]
        scores = torch.matmul(query, key.permute(0, 1, 3, 2)) / math.sqrt(d_k) #attention 得分， 
        """ 
        query [batch_size, nheads=8, seq_len, d_k=64]  key.permute[batch_size, nheads=8, , d_k=64, seq_len] 点积后scores维度-> [batch_size, n_heads=8, seq_len, seq_len]
        """

        if mask is not None:
            scores = scores.masked_fill(mask == 0, -1e9)
        p_attn = F.softmax(scores, dim = -1)#softmax后维度 [batch_size, n_heads=8, seq_len, seq_len]
        if dropout is not None:
            p_atten = dropout(p_attn)
        atten_res = torch.matmul(p_atten, value)#atten得分与value点积 [batch_size, n_heads=8, seq_len, d_k]
        return atten_res, p_atten
