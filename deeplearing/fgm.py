""" 
对于每个x:
  1.计算x的前向loss、反向传播得到梯度
  2.根据embedding矩阵的梯度计算出r,并加到当前embedding上相当于x+r
  3.计算x+r的前向loss,反向传播得到对抗的梯度累加到(1)的梯度上
  4.将embedding恢复为(1)时的值
  5.根据(3)的梯度对参数进行更新

"""
from pickletools import optimize
import torch
class FGM():
    """ 快速梯度对抗训练
    """
    def __init__(self, model):
        self.model = model
        self.backup = {}
 
    def attack(self, epsilon=1., emb_name='word_embeddings'):
        for name, param in self.model.named_parameters():
            if param.requires_grad and emb_name in name:
                self.backup[name] = param.data.clone()
                norm = torch.norm(param.grad)
                if norm != 0 and not torch.isnan(norm):
                    r_at = epsilon * param.grad / norm
                    param.data.add_(r_at)
 
    def restore(self, emb_name='word_embeddings'):
        for name, param in self.model.named_parameters():
            if param.requires_grad and emb_name in name:
                assert name in self.backup
                param.data = self.backup[name]
        self.backup = {}


fgm = FGM()#
for batch_input, batch_label in data:
    loss = model(batch_input, batch_label):
    loss.backward()
    fgm.attack()#
    loss_adv = model(batch_input, batch_label):#
    loss_adv.backward()#
    fgm.restore()#
    optimizer.step()
    model.zero_grad()