from numpy import indices
from torch import Tensor, log_
import torch
import transformers

class Solution:
    def beam_search_decoder(post: Tensor, top_k: int):
        """ 
        post shape [batch_size, seq_len, vocab_size] 
        return:
            indices(Tensor), a beam of sequence, shape = (batch_size, beam_size, seq_len)
            log_prob(Tensor), a beam of log likelhood of sequence. shape(batch_size, beam_size)
        """
        batch_size, seq_length, vocab_size = post.shape
        log_post = post.log()
        log_prob, indices = log_post[:, 0, :].topk(top_k, sorted=True)#first word top-k candidates
        indices = indices.unsqueeze(-1)
        for i in range(1, seq_length):
            log_prob = log_prob.unsqueeze(-1) + log_post[:, i, :].unsqueeze(1).repeat(1, top_k, 1)
            log_prob, index = log_prob.reshape(batch_size, -1).topk(top_k, sorted=True)
            indices = torch.cat([indices, index.unsqueeze(-1)], dim=-1)
        return indices, log_prob
    
    #transformers 库中beam search的实现
    def beam_search_generate(context: Tensor, batch_size = 3, max_length=20, min_length=2,
                                num_beams=2, bos_token_id=101, pad_token_id=0, eos_token_id=102):
        """ 
        准备初始输入
        在当前生成的序列长度未达到max_length时扩展生成序列
        准备最终输出的序列
         """
        # 建立beam容器，每个样本一个
        generated_hypes = [
            BeamHypotheses(num_beams, max_length, length_penalty, early_stopping=early_stopping)
            for _ in range(batch_size)
        ]
    
if __name__ == '__main__':
    s = Solution()
    post = torch.softmax(torch.randn([32, 20, 1000]), -1)
    indices, log_prob = s.beam_search_decoder(post, 3)