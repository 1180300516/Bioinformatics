#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int preSum[10000000];
char v[10000000];

//���룬����last����
int getLastArray(char *lastArray,const string &str){    ///�Ӵ�����
    int len=str.size();
    string array[len];
    for(int i=0;i<len;i++){
        array[i] = str.substr(i);
    }
    sort(array,array+len);
    for(int i=0;i<len;i++){
        lastArray[i] = str.at((2*len-array[i].size()-1)%len);
    }
    return 0;
}

int getCountPreSum(int *preSum,const string &str){
    int len=str.size();
    memset(preSum,0,len*sizeof(int));
    for(int i=0;i<str.size();i++){
        if(str.at(i) == '#')
            preSum[0]++;
        else
            preSum[str.at(i)-'A'+1]++;
    }

    for(int i=1;i<len - 1 ;i++)
        preSum[i] += preSum[i-1];
    return 0;
 }

//���룬ʹ��last���飬�ָ�ԭ�����ı���
int regainTextFromLastArray(char *lastArray,char *reGainStr,int *preSum){
    int len=strlen(lastArray);
    int pos=0;
    char c;
    for(int i=len-1;i>=0;){
        reGainStr[i] = lastArray[pos];
        c = lastArray[pos];
        pos = preSum[c-'A']+count(lastArray,lastArray+pos,c);
        i--;
    }
    return 0;
}

 int main (){
    char c;
    int i = 0;
    FILE *fp;//�ļ�ָ��
    fp = fopen("test.txt","r");//���ı���ʽ���ļ���
    if(fp == NULL) //���ļ�����
        return -1;
    while((c = getc(fp))!=EOF)
    {
        if(c != '\n')
        {
            v[i] = c;
            i++;
        }

    }
    v[i] = '#';
    string str = v;
    int len=str.size();
    char *lastArray = new char[len+1];
    char *reGainStr = new char[len+1];
    lastArray[len]='\0';
    reGainStr[len]='\0';
    getCountPreSum(preSum,str);
    getLastArray(lastArray,str);
    regainTextFromLastArray(lastArray,reGainStr,preSum);
    cout<<"       str: "<<str<<endl;
    cout<<"lastArray : "<<lastArray<<endl;
    cout<<"reGainStr : "<<reGainStr<<endl;
    delete lastArray;
    delete reGainStr;
    return 0;
 }
