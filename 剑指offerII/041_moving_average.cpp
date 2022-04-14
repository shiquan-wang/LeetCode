#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/* 
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。

 */

class MovingAverage{
private:
    queue<int> window;
    int win_size;
    double res;
public:
    MovingAverage(int size){
        while (!window.empty())
        {
            window.pop();
        }
        win_size = size;
        res = 0;
    }

    double next(int val){
        if(window.size() == win_size){
            res -= window.front();
            window.pop();
        }
        window.push(val);
        res += val;
        return res/window.size();
    }
};