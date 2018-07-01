//参与了西邮杯，里面有一道球互满数的题，题目是一个数a的所有因子之和
//等于另一个数b，b的因子之和也等于a，这样的数称为互满数，球0-10000内的
//互满数，输出格式（a，b）a<b；
//直接暴力，肯定超时，要减少一层循环
int yinzi_sum(int n){
//求一个数的因子之和
}
int main(){
    int i;
    for(i = 0;i < 10000;i++)
    if(yinzi_sum(yinzi_sum(i)) == i &&
    i<yinzi_sum(i))
    printf(i,yinzi_sum(i));
}
