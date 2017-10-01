/*
#include <iostream>
#include <vector>
using namespace std;


//  将一个数组中的两个相邻有序区间合并成一个
//  a : 包含两个有序区间的数组
//  start: 第一个有序区间的起始地址
//  mid :  第一个有序区间的结束地址，也是第二个有序区间的起始地址
//  end :  第二个有序区间的结束地址

void merge(vector<int> a, int start, int mid, int end){
    int *tmp = new int[end - start + 1];     // tmp 是汇总2个有序区的临时区域
    int i = start;          // 第一个有序区的索引
    int j = mid + 1;        // 第二个有序区的索引
    int k = 0;              // 临时区域的索引

    while (i <= mid && j <= end){        // 连续比较两个有序区的大小
        if (a[i] <= a[j]){
            tmp[k++] = a[i++];
        }
        else{
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid ){                // 确保把两个数组都放入临时区域中
        tmp[k++] = a[i++];
    }
    while (j <= end){
        tmp[k++] = a[j++];
    }
    //将排序后的临时区域存入原来的数组中
    for (i = 0; i < k; i++){
        a[i + start] = tmp[i];
    }
    delete []tmp;                      // 删除临时区域

}

// 归并排序（从上往下）
// arr : 待排序的数组
// start: 数组的起始地址
// end  : 数组的结束地址

void merge_sort_up2down(vector<int>& arr, int start, int end){
    if(arr.empty() || start > end){
        return ;
    }

    int mid = (start + end)/2;
    merge_sort_up2down(arr, start, mid);        // 递归排序数组的前半部分
    merge_sort_up2down(arr, mid + 1, end);      // 递归排序数组的后半部分

    merge(arr, start, mid, end);               // 合并两个分开的数组
}

int main(){
    vector<int> arr;     // 存放待排序的数组
    int temp;            // 作为输入时的缓存变量
    cout << "请输入数组：";
  //  while(cin >> temp){
  //      arr.push_back(temp);  // 将输入的数字存入数组中
  //  }
    arr = {12,16,8,89};
    merge_sort_up2down(arr, 0, arr.size()-1);    //调用函数排序
    cout << "排序后结果为：";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";             //输出排序后的结果
     }
    return 0;
}
*/
/*
#include<iostream>
#include <vector>
using namespace std;
  void helper (vector<string> res, string digits, string curr, int index, vector<string> keyvalue){

        if (index == digits.size()){      // 最后一层退出的条件，当索引等于数字的位数时，说明到了最后一层
            if (curr.length() != 0){      // 若是当前的字符串长度不为0，则将其添加到结果中
                res.push_back(curr);      //
            }
            return;
        }
        string tmp = keyvalue[digits[index] - '0']; // 找到数字对应的字符串，比如2对应的"abc"
        for (int i = 0; i < tmp.length(); i++){
            string next = curr + tmp[i];         //  每次循环将这一层选择的字符添加到next中
            helper(res, digits, next, index + 1, keyvalue);  // 进入下一层
        }
    }
vector<string> letterCombinations(string digits) {
vector<string> res, keyvalue;
    keyvalue[0]= {" "};
    keyvalue[1]= {" "};
    keyvalue[2]= {"abc"};
    keyvalue[3]= {"def"};
    keyvalue[4]= {"ghi"};
    keyvalue[5]= {"jkl"};
    keyvalue[6]= {"mno"};
    keyvalue[7]= {"pqrs"};
    keyvalue[8]= {"tuv"};
    keyvalue[9]= {"wxyz"};
    if (digits.size() == 0){
            return res;
    }

    helper(res, digits, "", 0, keyvalue);
    return res;
}


int main()
{
    string digits ="23";
    vector<string> res  = letterCombinations(digits);

    return 0;
}

*/
/*
#include <iostream>
#include <vector>
using namespace std;
int FindIndexOfbit1(int number){
        bool ret = 0, count = 0;
        if (number && 1 == 1){      // 若是从右边起第一位出现了1，则返回索引0
            return 0;
        }
        while (ret != 1 && number != 0){
            number = number >> 1;
            ret = number && 1;
            count++;
        }
        return count;
    }
    bool Isbit1(int number, int index){
        number = number >> index;
        return ( number & 1 );
    }
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() == 0){
            return;
        }
        int res = 0, result1 = 0, result2 = 0;
        for (int j = 0; j < data.size(); j++){
            res = res ^ data[j];
        }
        int indexofbit1 = FindIndexOfbit1(res);
        for (int i = 0; i < data.size(); i++){
            if ( Isbit1(data[i], indexofbit1) == false){
                result1 = result1 ^ data[i];
            }
            else{
                result2 = result2 ^ data[i];
            }
        }
        *num1 = result1;
        *num2 = result2;
        return;
    }

int main()
{
    vector<int> arr = {2,4,3,6,3,2,5,5};
    int num1 =0, num2 =0;
    int * p1 = &num1;
    int * p2 = &num2;
    FindNumsAppearOnce(arr, p1, p2);
    cout << num1 <<num2 ;
    return 0;
}
*/
/*
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int length ,ans = 0;
    vector<char> s;
    char tmp;
    while (cin >> tmp){
        s.push_back(tmp);
    }
    length = s.size();
    int index1 = 0, index2 = length / 2, indexall = length - 1;
    while(index1 <= index2){
        //indexall = indexall - 2;
        length = length -2;
        index1 = 0;
        index2 = length / 2;
        if (s[index1] != s[index2]){
            continue;
        }
        while (s[index1] == s[index2] && index1 < length/2){
            index1++;
            index2++;
        }
        if (index1 == (length / 2)){
            break;
        }
    }
    ans = index2 ;

    cout << ans << endl;
    return 0;
}

*/

/*

# include<iostream>
using namespace std;
int main()
{
     const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    cout << input[0][2] << endl;
    return 0;
}
*/
/*

#include <stdio.h>
#include <assert.h>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

int resolve(const char* input) // solution  for the problem
{
    char * cur = const_cast<char*>(&input[0]);


    return 0;
}

int main(int argc, char* argv[])
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
*/
/*
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int num, n,tmp;
    cin >> num;
    for (int i = 1; i <= num; i++){
        cin >> n;
        deque <int> ori;
        for (int j = n; j > 0; j--){
            ori.push_front(j);  // 将一个值压入到当前队列的头部
            tmp = ori.back();   // 获取当前队列的队尾值
            ori.pop_back();    //弹出队列的队尾值
            ori.push_front(tmp); // 将队尾值放到队列的头部
        }
        if (i != num){
            for (int j = 0; j < n; j++){
                 j != n - 1 ? cout << ori[j] << " ": cout << ori[j];
            }
            cout << endl;
        }
        else{
            for (int j = 0; j < n; j++){
                 j != n - 1 ? cout << ori[j] << " ": cout << ori[j];
            }
        }
    }
    return 0;
}
*/
/* 华为机试题
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack<char> stack1;
    string str;
    while (getline(cin, str)){
        int len = str.size();
        int i = len - 1;
        while (i >= 0){
            while (str[i] != ' ' && i>=0){
                stack1.push(str[i]);
                i--;
            }
            --i;
            while (!stack1.empty()){
                cout << stack1.top();
                stack1.pop();

            }
            if (i >= 0){
                cout << " ";
            }
        }
    }
    return 0;
}

*/
/* 小易喜欢的单词，已AC，但是缺少一种情况
#include <iostream>
#include <string>
using namespace std;
int main(){
    int tmp;
    string str;

    while (getline(cin, str)){
        bool flag = 1;
        int len = str.size();
        for (int i = 0; i <= len - 1; i++){ // 检查是否都是大写字母和是否有连续相等的字母
            if (str[i] < 'A' || str[i] > 'Z'){
                cout << "Dislikes";
                flag = 0;
                break;
            }
            if (i >= 1 && str[i] == str[i - 1]){
                cout << "Dislikes";
                flag = 0;
                break;
            }
        }
        if (flag){
            cout << "Likes";
        }
    }
    return 0;
}
*/

//利用正则表达式判断电子邮件是否合法
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>  // regular expression 正则表达式

using namespace std;

int main()
{
    string email_address;
    string user_name, domain_name;

    regex pattern("([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
    // 正则表达式，匹配规则：
    // 第1组（即用户名），匹配规则：0至9、A至Z、a至z、下划线、点、连字符之中
    // 的任意字符，重复一遍或以上
    // 中间，一个“@”符号
    // 第二组（即域名），匹配规则：0至9或a至z之中的任意字符重复一遍或以上，
    // 接着一个点，接着a至z之中的任意字符重复2至3遍（如com或cn等），
    // 第二组内部的一组，一个点，接着a至z之中的任意字符重复2遍（如cn或fr等）
    // 内部一整组重复零次或一次


    // 输入文件结尾符（Windows用Ctrl+Z，UNIX用Ctrl+D）结束循环
    while ( cin >> email_address )
    {
        if ( regex_match( email_address, pattern ) )
        {
            cout << "您输入的电子邮件地址合法" << endl;

            // 截取第一组
            user_name = regex_replace( email_address, pattern, string("$1") );

            // 截取第二组
            domain_name = regex_replace( email_address, pattern, string("$2") );

            cout << "用户名：" << user_name << endl;
            cout << "域名：" << domain_name << endl;
            cout << endl;
        }
        else
        {
            cout << "您输入的电子邮件地址不合法" << endl << endl;
        }
    }
    return EXIT_SUCCESS;
}
*/
/*
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int res = 0, N, m;
    while (cin >> N >> m){
        res = N + m;
        cout << res;
    }

    cout << res;
    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int main(){
    int res;
    string ress;
    string str;
    stack <int> stack1;
    while(cin >> str){
        res = 0;
        int count = -1, tmp = 0;
        int len = str.size();
        for (int i = len - 1; i >= 2; i --){
            count ++;
            if (str[i] >= 'A' && str[i] <= 'F'){
                res += (str[i] - 'A' + 10) * pow (10, count);
            }
            else{
                res += (str[i] - '0') * pow (10, count);
            }
        }
        while (res != 0){
            tmp = res % 10;
            stack1.push(tmp);
        }

        while (!stack1.empty()){
            int tmp = stack1.top();
            stack1.pop();
            ress.push_back(tmp);

        }
        cout << res << endl;
    }

    return 0;
}


*/
/*
#include <iostream>
using namespace std;
int main(){
    int N = 0, K = 0;
    int maxlen, maxcur, sum;
    cin >> N;
    int  arr[N + 1];
    int tmp = 0;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        arr[i] = tmp;
    }
    cin >> K;
    for (int i = 0; i < N; i++){
        sum = 0;
        for (int j = i; j < N; j++){
            maxcur = 0;
            sum += arr[j];
            if (sum % K == 0){
                maxcur = j - i + 1;
            }
        }
        if (maxcur > maxlen){
            maxlen = maxcur;
        }

    }
    cout << maxlen;
    return 0 ;
}

*/

/*
#include <iostream>
#include <algorithm>
//#include <vector>
using namespace std;
int main(){
    int res = 0;
    int K, n, m;
    cin >> K >> n >> m;
    int arr[n][m];
    int len = n*m;
    int data[len];
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            data[index] = arr[i][j];
            index ++;
        }
    }
    sort(data, data + len);
    res = data[K-1];
    int row = 0, col = 0;
    int sorted[K];
    sorted[0] = arr[0][0];

    for (int i = 1,j = 1; i < n && j < m; ){
        if (arr[i] < arr[j])
    }
    return 0;
}

*/
/*
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M, K, M1;
    int arr[10001][101];
    int arr1[1001][101];
    int n;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> M;
        arr[i][0] = M;
        for (int j = 1; j < M + 1; j++){
            cin >> arr[i][j];
        }
    }
    cin >> K;
    vector<vector<int>> P(K); // 输出位置的数组
    for (int i = 0; i < K; i++){
        cin >> M1;
        arr1[i][0] = M1;
        for (int j = 1; j < M1 + 1; j++){
            cin >> arr1[i][j];
        }
    }
    int count = 0; // 计数
    for (int i = 0; i < K; i++){
        P[i][0] = count;
    }
    for (int i = 0; i < K; i++){
        count = 0;
        for (int j = 0; j < N; j++){
            int su = 0;
            if (arr[j][0] == arr1[i][0]){ // 判断相等
                for (int l = 0; l < arr[i][0]; l++){
                    if (arr[j][l] != arr[i][l]){
                        break;
                    };
                    su++;
                }
                if (su == arr[i][0]){
                    count++;
                    P[i][0] = count;
                    P[i].push_back(j + 1) ;  // 位置存储起来
                }

            }

            if( (arr[j][0] - arr1[i][0] == 1 ) || (arr[j][0] - arr1[i][0] == -1 )){ // 判断是否相似
                set<int> tmp1;
                set<int> tmp;
                for (int q = 1; q <= arr1[i][0]; q++){
                    tmp1.insert(arr1[i][q]);
                }
                for (int q = 1; q <= arr[i][0]; q++){
                    tmp.insert(arr[i][q]);
                }
                int shu =0;
                for (int q = 0; q < tmp1.size(); q++){
                    if (tmp1[q] != tmp[q]){
                        break;
                    }
                    shu++;
                }
                if (shu == tmp1.size()){
                    count++;
                    P[i][0] = count;
                    P[i].push_back(j + 1) ;  // 位置存储起来
                }
            }
        }
    }

    for (int i = 0; i < K; i++){
        for (auto  :)
    }

    return 0;
}
*/
/*
#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    for (auto u: s){
       if (u != s.end()){
            cout << u <<" ";
        }
        else{
            cout << u;
        }
        cout << u ;

    }


    return 0;
}

*/

/*
#include <iostream>
//#include <vector>
#include <iostream>
//#include <vector>
#include <string>
using namespace std;
int main(){
    int res = 0;
    string str;
    cin >> str;
    int len = str.size();
    int maxcount = 0;
    int ptr1 = 0, count = 0;
    int ptrCur = 0;
    int i = 0;

    for (int i = 0; i < len;){
        if (str[i] >= '0' && str[i] <= '9'){
            ptrCur = i;
            i++;
            while (str[i] >= '0' && str[i] <= '9'){
                i++;
            }
            count = i - ptrCur;
            if (count >= maxcount){
                maxcount = count;
                ptr1 = ptrCur;
            }
        }
        else{
            i++;
        }
    }
    if (maxcount == 0){
        cout <<""<<endl;
    }
    else{
        for (int i = ptr1; i < maxcount + ptr1; i++){
            cout << str[i];
        }
        cout << endl;
        cout << maxcount;
    }

    return 0;
}

*/
/*

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    float res = 0.00000000;
    float cur = 0.00000000;
    for (int i = 1; i < n; i++){

        cur = arr[i] - arr[0];
        if(cur >= 180 ){
            cur = 360.00000000 - cur;
        }
        if (cur > res){
            res = cur;
        }
    }
    cout<<fixed<<setprecision(8) << res;
    return 0;
}

*/
/*

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    float res = 0.00000000;
    float cur = 0.00000000;
    int i = n - 1;
    while ( i >= 0){
        cur = arr[i] - arr[0];
        if(cur <= 180 ){
            if (cur >= res){
                res = cur;
                break;
            }
        }
        else{
            cur = 360.00000000 - cur;
            if (cur > res){
                res = cur;
            }

        }
        --i;
    }
    cout<<fixed<<setprecision(8) << res;
    return 0;
}

*/
/*
#include<iostream>
using namespace std;
int main(){
    int n, k = 2;
    int res = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[n];
    }
    int count = 0;
    int i = 0;
    while(i < n){
        count = 0;
        if (arr[i] ^ arr[i + 1] == 0){
             while (arr[i] ^ arr[i + 1] == 0){
                i++;
                count++;
            }
            if(count >= 2){
               res ++;
            }
        }
        else{
            i++;
        }
    }
    k = res;
    cout << k;
    return 0;
}
*/

/*

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    int count = 0,ans = 0;
    string str;
    cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++){
       if (str[i] == 'R'){
           count++;
       }
    }
    int countOfG = len - count;
    string copystr;
    for(int i = 0; i < count; i++){
       copystr.push_back('R');
    }
    for(int i = 0; i < countOfG; i++){
       copystr.push_back('G');
    }
    for(int i = 0; i < len; i++){
       if (str[i] != copystr[i]){
           ans++;
       }
    }


    cout << ans << endl;
    return 0;
}

*/

/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n,ans = 0, tmp;
    vector<int> arr;
    set<int> data;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    int i = 0;
    while (i < n){
        for (int j = 1; j < arr[i]; j++){
            set<int>::iterator it;
            it=data.find(j);    //查找键值为j的元素
            if(it==data.end()){   //若找不到
                data.insert(j);
                ans++;
            }
        }

        i++;
    }
    cout << ans << endl;
    return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll computer(ll n){
    ll temp = n;
    ll count = 0;
    if (temp < 101){
        temp = (n / 10) % 10;
        count = temp - 1;
        if (n % 10 >= temp){
            count ++;
        }
    }
    return count;
}
ll qiyi(ll n){
    return computer(n % 100) + 10*(n / 100);
}

int main() {
    ll L,R;
    cin >> L >> R;
    cout << (qiyi(R)-qiyi(L-1))<<endl;
    return 0;
}
*/
/*
#include <iostream>
#include <string>
using namespace std;
int main(){
    int res = 0;
    string input;
    string output;
    while(cin >> input){
        for (int i = 0; i < input.size(); i++){
            cout << input[i] + '48' ;
        }
    }

    return 0;
}

*/
/*
#include <iostream>
#include <iostream>
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
using namespace std;
int reverse(long int x);

int main(){
    long int input,res = 0;
    cin >> input;
    res = reverse(input);
    cout << res;
    return 0;
}
int reverse(long int x){
     long int t = 0;
     while (x != 0){
        if (t >INT_MAX / 10 || t <(INT_MIN) / 10)
             return 0;
        t= t * 10 + x % 10;
        x /= 10;
     }
     return t;
}
*/

/*

#include <iostream>
#include <vector>
using namespace std;
int print_num(int n, int m, vector<int>& num, int & ret)
{
    //递归出口
    if (m<= 0 || n <= 0)
        return 0;
    //找到合适的解法
    if (m == n)
    {
        for (int i = 0; i < num.size(); i++)
        {
            //cout << num[i] << "\t";
            ret++;
        }
        //cout << n;
        //cout << endl;
        return ret;
    }
    num.push_back(n);
    print_num(n-1, m - n, num);
    num.pop_back();
    print_num(n-1,m,num);
    return ret;
}
int main() {
    int n,m;
    int res = 4;
    cin >> n >> m;
    vector<int> data;
    res = print_num(n, m, data);
    cout << res;
    return 0;
}*/
/*
#include <iostream>
#include <vector>
using namespace std;
int print_num(int n, int m, vector<int>& num, int & ret)
{
    //递归出口
    if (m<= 0 || n <= 0)
        return 0;
    //找到合适的解法
    if (m == n)
    {
        for (int i = 0; i < num.size(); i++)
        {
            //cout << num[i] << "\t";
            ret++;
        }
        //cout << n;
        //cout << endl;
        return ret;
    }
    num.push_back(n);
    print_num(n-1, m - n, num, ret);
    num.pop_back();
    print_num(n-1,m,num, ret);
    return ret;
}
int main() {
    int n,m;
    int res = 0;
    cin >> n >> m;
    vector<int> data;
    print_num(n, m, data, res);
    cout << res;
    return 0;
}
*/



