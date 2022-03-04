import java.math.BigInteger;
import java.util.Scanner;

public class D {
    static long[] cat = new long[1050];
    static long[][] memo = new long[1050][1050];
    static boolean[][]check = new boolean[1050][1050];
    public static void factorial(){
        cat[0]=1;
        cat[1]=1;
        for(int i=2;i<=1040;i++){
            cat[i]=0;
            for(int j=0;j<i;j++){
                cat[i]+=(cat[j]*cat[i-j-1])%1009;
                if(cat[i]>=1009)cat[i]= cat[i]%1009;
            }
        }
    }


    public static int valor(long s){
        String auxx = String.valueOf(s);
        BigInteger bg = new BigInteger(auxx);
        BigInteger bgm1 = bg.add(BigInteger.ONE);
        BigInteger aux = bg.multiply(bgm1);
        aux = aux.divide(BigInteger.TWO);
        BigInteger m = aux.mod(new BigInteger("1009"));
        int sol = m.intValue();
        sol++;
        while(sol<0){
            sol+=1009;
        }
        return sol%1009;
    }

    static long moch(int i, int p, Pair[] mochila){
        if(p<0){
            return -10000000;
        }
        if(i >= mochila.length || p==0){
            return 0;
        }
        if(!check[i][p]){
            check[i][p]=true;
            memo[i][p]= Math.max(moch(i+1, p-mochila[i].peso, mochila)+ mochila[i].valor, moch(i+1, p, mochila));
        }
        return memo[i][p];
    }

    public static void main(String[] args) {
        factorial();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int c = in.nextInt();
        Pair[] pairs = new Pair[n];

        for(int i=0;i<n;i++){
            pairs[i]=new Pair(valor(in.nextLong()),0);
        }
        for(int i=0;i<n;i++){
            pairs[i].peso= (int) cat[in.nextInt()];
        }

        for(int i = 0; i < n; i++) {
            System.out.println(String.format("%s %s", pairs[i].valor, pairs[i].peso));
        }
        System.out.println(moch(0, c, pairs));
    }

}
class Pair{
    int valor, peso;

    public Pair(int valor, int peso) {
        this.valor = valor;
        this.peso = peso;
    }
}