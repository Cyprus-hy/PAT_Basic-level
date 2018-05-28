# PAT_Basic-level
1001 水题 简单模拟 偶数每次除2，奇数每次乘3加1再除2 注意每次处理完后重新判断是奇数还是偶数

1002 水题 简单大数运算 先用字符串数组存储好每一位对应的拼音，对每一位求和后再拆开数字，对着拼音数组输出

1004 水题 首先定义结构体存储学生信息，再对学生成绩进行排序，自己写了个冒泡，但其实用vector存结构体再用容器本身的sort排序更省时间

1005 简单题 首先定义结构体存储每个数字的信息（主要包括数字本身以及它能覆盖的数），然后写一个函数，寻找数字a所能覆盖的数，存到数组n里，对于每一个数字的覆盖数组n，都将它与给出的这列数字比较，判断是否为关键数（这里用了三重循环，不过处理的数据量比较小，暴力还是能过）

1006 水题 分解每一位数字，根据题意循环输出即可

1007 水题 从2到给的数字区间找素数，然后判断相邻两个的差是否为2，计数即可

1008 水题 因为不让再用数组，所以把原来的数组开大一点，存两次数据。循环右移m其实就是小标加m再取模的过程

1009 水题 这道题的关键是要找到句子中空格的位置（包括句首以及句尾的空格），然后从倒数第二个空格开始，连续输出它与下一个空格间的内容

1010 水题 这里我用的do-while语句输入（一个小技巧，当输入不给数据量的时候，可以用如下输入方式）

do{

cin>>a;

count++;//计数

while(cin.get()!='\n');

然后分两种情况，即存在常数项和不存在，存在常数项又得区分是否为零多项式，因为零多项式是需要输出的，而非零多项式的常数项不输出

1011 水题 这个数据范围用longlong定义再加一下就好

1012 水题 第一类数是10的倍数，第二类判断一下-1的次方再进行混合运算，第三类计个数，第四类求个和，第五类可以先用一个数组单独存起来再sort一下

1013 简单题 这道题它最多就是第10000个素数，所以先把前10000个素数找到存在数组，然后输出的时候就从这个数组遍历，注意一下输出的格式

1014 简单题 这道题有点坑，首先第一对相同的大写英文字符必须要在A到G之间，然后第二对相同的字符可以是0到9之间的数字，也可以是A到N之间的大写字符，最后一对相同的字符排除掉&，输出注意补0

1015 中档题 这道题的数据量很大，所以很容易出现超时或者数组越界的情况。我的做法是，首先用vector进行数存储，然后用容器自带的sort函数来节省时间，这里需要自己定义一个比较函数cmp，最后说明一下scanf与printf是要比cin和cout快的。至于题目本身的逻辑很简单，分四类比较就好

1016 水题，找出A中Da以及B中Db的位数即可，A、B数据量大用string存

1017 中档题 简单的除法模拟 除数很大，用string存。然后从高位开始算，如果第j位大于被除数，直接除即可，然后余数再赋值给第j位；如果小于，则需要从第j+1位借位运算，余数赋值给第j+1位，特别注意只有此时才执行j++。这个循环因为有j+1，所以实际上做到了倒数第二位。对于除数是1位的，一定要单独考虑。

1018 水题 定义结构体存每一回合数据，vector存结构体。每一回合根据规则判断胜负，甲胜的次数就是乙输的次数。记录甲乙每种手势胜的次数，然后找到最大的对应的下标，输出手势字符。

1021 水题 字符串输入，每位数计数即可

1022 水题 进制转换，注意倒序以及和为0的情况

1023 水题 将第一个不为0的数作为首位，其余位从小到大输出即可

1024 简单题 这道题其实逻辑很简单，但是坑有点多。首先分类，看它的指数是大于0还是小于0。小于0的话就前面补0，大于0的话就后面加0。但有一种情况特殊，就是E的次方数小于小数部分的位数，此时小数点仍然右移，但后面不会添0（测试点4过不了就是因为这个）。还有一种情况是指数为0的情况，也必须单独考虑（但测试点里好像没有这个坑，不写也能过）。
