-- 一个完整的SELECT语句包括6个子句，其中前面的2个子句是必不可少的，其他子句可以省略。

-- SELECT 语句的完整格式如下：
-- SELECT [DISTINCT] 目标列名序列-----要查看的列
-- FROM 表名或视图名------------------数据来源
-- [WHERE 条件表达式]----------------查询条件
-- [GROUP BY + 列名] --------------------分组依据
-- [HAVING + 组条件表达式] ---------分组条件
-- [ORDER BY + 列名 + [ASC|DESC]序列]----排序依据

/* 执行顺序：
from -> join -> on -> where -> group by -> avg,sum等聚合函数 -> having -> select -> distinct -> order by -> limit
 */

/* 简单处理查询结果 */
-- 查询结果去重 distinct
SELECT DISTINCT university FROM user_profile

-- 使用LIMIT限制结果集 LIMIT 接受一个或两个数字参数。参数必须是一个整数常量。
SELECT device_id FROM user_profile LIMIT 2

-- 改变列标题(取别名) 列名 | 表达式 [ AS ] 新列名
SELECT device_id AS user_infos_example FROM user_profile LIMIT 2

/* 条件查询 */
-- 基础排序
-- 查找后排序， ORDER BY <列名> [ASC | DESC ] asc升序， desc降序
SELECT age FROM user_profile ORDER BY age ASC

-- 多列排序 ORDER BY gpa ASC,age ASC,在多个排序条件中加入逗号分割
SELECT device_id, gpa, age FROM user_profile ORDER BY gpa ASC,age ASC

-- 查找后降序排列
SELECT device_id, gpa, age FROM user_profile ORDER BY gpa DESC, age DESC

-- 基础操作符

/* -- 统计2021年8月份所有练习过题目的总用户数和练习过题目的总次数
-- 限定条件：2021年8月份，匹配date字段即可，匹配方法主要有三种：
-- （1）like语法：date like "2021-08%"
-- （2）year、month函数：year(date)='2021' and month(date)='08'；
-- （3）date_format函数：date_format(date, '%Y-%m')='2021-08';
-- 2：总用户数：count函数计数，因为用户有重复，所以需要distinct去重，即count(distinct device_id)
-- 3：总次数：count(question_id)即可
SELECT count(DISTINCT device_id) as did_cnt, 
       count(question_id) as question_cnt
FROM 
    question_practice_detail
WHERE date like "2021-08%" */

SELECT device_id, university FROM user_profile WHERE university = "北京大学"
SELECT device_id, gender, age, university FROM user_profile WHERE age > 24
SELECT device_id, gender, age FROM user_profile WHERE age between 20 and 23
SELECT device_id, gender, age, university FROM user_profile WHERE university != "复旦大学"
SELECT device_id, gender, age, university FROM user_profile WHERE age IS NOT NULL /* 筛选不是空值的数据 */

-- 高级操作符
SELECT device_id, gender, age, university, gpa FROM user_profile WHERE gpa > 3.5 AND gender = "male"
SELECT device_id, gender, age, university, gpa FROM user_profile WHERE gpa > 3.7 OR university = "北京大学"
-- 找到学校为北大、复旦和山大的同学进行调研，请你取出相关数据。 WHERE 列名 IN (范围)
SELECT device_id, gender, age, university, gpa FROM user_profile WHERE university IN ('北京大学', '复旦大学', '山东大学')
SELECT device_id, gender, age, university, gpa FROM user_profile WHERE (gpa > 3.5 and university = '山东大学') OR (gpa > 3.8 AND university = '复旦大学')
-- 字符匹配， 列名 [NOT] LIKE, _ 匹配任意一个字符， % 匹配0个或多个字符; []匹配[]中任意一个字符 [^]不匹配[]中的任意一个字符
SELECT device_id, age, university FROM user_profile WHERE university like '北京%'

-- 高级查询

-- 计算函数
SELECT gpa FROM user_profile WHERE university = '复旦大学' ORDER BY gpa DESC LIMIT 1
SELECT max(gpa) FROM user_profile WHERE university = '复旦大学'
    -- 看一下男性用户有多少人以及他们的平均gpa是多少
SELECT count(gender) AS male_num, avg(gpa) as avg_gpa FROM user_profile WHERE gender = 'male'
    -- 浮点数的平均值可能小数点位数很多，保存一位小数如下
SELECT count(gender) AS male_num, round(avg(gpa), 1) as avg_gpa FROM user_profile WHERE gender = 'male'
-- 分组查询
    -- 分别计算出每个学校每种性别的用户数、30天内平均活跃天数和平均发帖数量。
SELECT 
    gender, 
    university, 
    count(*) as user_num, round(avg(active_days_within_30), 1) as avg_active_day, 
    round(avg(question_cnt), 1) as avg_question_cnt
FROM 
    user_profile
GROUP BY 
    gender, university
    -- 19取出平均发贴数低于5的学校或平均回帖数小于20的学校
SELECT
    university,
    round(avg(question_cnt), 1) as avg_question_cnt,
    round(avg(answer_cnt), 1) as avg_answer_cnt
FROM
    user_profile
GROUP BY
    university
HAVING
    avg_question_cnt < 5 OR avg_answer_cnt < 20
    -- 20 分组排序 查看不同大学的用户平均发帖情况 按照平均发帖情况进行升序排列
SELECT
    university, round(avg(question_cnt)) as avg_question_cnt
FROM
    user_profile
GROUP BY
    university
ORDER BY
    avg_question_cnt ASC

-- 多表查询
/* 
连接查询包括内连接、外连接和交叉连接等
内连接
内连接语法如下：

SELECT …
FROM 表名
[INNER] JOIN 被连接表
ON 连接条件

执行连接操作的过程,首先取表1中的第1个元组，然后从头开始扫描表2，逐一查找满足连接条件的元组，
找到后就将表1中的第1个元组与该元组拼接起来，形成结果表中的一个元组。 表2全部查找完毕后，再取表1中的第2个元组，然后再从头开始扫描表2， …
重复这个过程，直到表1中的全部元组都处理完毕为止。
可以为表提供别名，其格式如下： <源表名> [ AS ] <表别名>  如果为表指定了别名，则查询语句中其他所有用到表名的地方都要使用别名
 */

/* 外连接：
左连接：
SELECT …
FROM 表名
LEFT JOIN 被连接表 ON 连接条件

 */
    -- 21查看所有来自浙江大学的用户题目回答明细情况
SELECT q.device_id, q.question_id, q.result
FROM user_profile AS u INNER JOIN question_practice_detail AS q
ON u.device_id = q.device_id
WHERE university = '浙江大学'

SELECT device_id, question_id, result
FROM question_practice_detail as qpd
WHERE device_id = (SELECT device_id FROM user_profile WHERE university = '浙江大学')
-- 链接查询
    -- 22 统计每个学校答过题用户的平均答题数
SELECT 
    u.university, 
    count(q.question_id)/count(distinct q.device_id) as avg_answer_cnt
FROM
    user_profile as u 
    INNER JOIN question_practice_detail as q ON u.device_id = q.device_id
GROUP BY
    university
    -- 23统计每个学校各难度的用户的平均刷题数

SELECT 
    qpd.university, qd.difficult_level, round(count(qpd.question_id) / count(distinct qpd.device_id), 4) as avg_answer_cnt
FROM
    question_practice_detail as qpd
    LEFT JOIN user_profile as up ON qpd.device_id = up.device_id
    LEFT join question_detail as qd ON qpd.question_id = qd.question_id
GROUP BY university, difficult_level

    --24 统计每个用户的平均刷题数
SELECT 
    university, round(count(qpd.question_id) / count(distinct qpd.device_id), 4) as avg_answer_cnt
FROM
    question_practice_detail as qpd
    JOIN user_profile as up ON up.device_id = qpd.device_id
    JOIN question_detail as qd ON qd.question_id = qpd.question_id
WHERE university = '山东大学'
GROUP BY qd.difficult_level

-- 组合查询
    --25查找山东大学或者性别为男生的信息
SELECT device_id, gender, age, gpa
FROM user_profile
WHERE university = '山东大学' 
UNION ALL
SELECT device_id, gender, age, gpa
FROM user_profile
WHERE gender = 'male'

/* 
UNION的作用
UNION运算符用于组合两个或更多SELECT语句的结果集。
UNION使用前提,UNION中的每个SELECT语句必须具有相同的列数
UNION具有排除重复记录行的功能, UNION ALL包含重复值
 */
-- 常用函数

-- 条件函数
    --26计算25岁以上和一下的用户数量
select '25岁以下' as age_cnt, count(distinct device_id) as number
from user_profile
where age < 25
union all
select '25岁及以上' as age_cnt, count(distinct device_id) as number
from user_profile
where age >= 25
/*     CASE函数是一种多分支的函数，可以根据条件列表的值返回多个可能的结果表达式中的一个。
        可用在任何允许使用表达式的地方，但不能单独作为一个语句执行。 */
-- 日期函数 获取年月日 year(date), month(date), day(date) 或者 date_format(date, "%Y-%m") = "202108"
    -- 2021年8月每天用户练习题目的数量
select day(date) as day, count(question_id) as question_cnt
from question_practice_detail
where year(date) = 2021 and month(date) = 8
group by date
-- 文本函数
-- 窗口函数
select d.DNAME, avg(e.PER), avg(p.GRADE)
from Dept d, Emp e, Pergrade p
where d.DEPTNO = e.DEPTNO and (e.PER between p.LOPER and p.HIPER)
group by e.DEPTNO
order by avg(p.GRADE) desc
limit 1