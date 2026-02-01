import java.io.PrintWriter;
import java.util.Scanner;

public class PizzaMatematica {
    static long MOD = 1009;
    static long[] catalan = new long[1009+2];
    static long[][] memo = new long[1002][1002];
    static boolean[][] visit = new boolean[1002][1002];
    static long[] valores,pesos;
    static int nIngrtedientes,capacidad;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        nIngrtedientes = sc.nextInt();
        capacidad = sc.nextInt();

        valores = new long[nIngrtedientes];
        pesos = new long[nIngrtedientes];

        for (int i = 0; i < nIngrtedientes; i++) {
            long val = (sc.nextLong()%MOD);
            long sum = 1+((val+1)*val*invert(2));
            valores[i] = sum % MOD;
        }
        catalanS();//Mas programacion lateral
        for (int i = 0; i < nIngrtedientes; i++) {
            long val = (sc.nextLong()%MOD);
            pesos[i] = catalan[(int)val];
            pw.println(String.format("%s %s", val, pesos[i]));
        }
        
        long sol = DP(capacidad, 0);
        if (sol == -1 )sol = 0;
        for(int i = 0; i < nIngrtedientes; i++) {
        }
        pw.println("Ans: ");
        pw.println(sol);
        pw.flush();
        pw.close();
    }

    public static long DP (int pesoDisp,int pos){
        if (pesoDisp<0)return -1;
        if (pos>=nIngrtedientes)return 0;
        if (visit[pesoDisp][pos])return memo[pesoDisp][pos];
        long v1 = DP(pesoDisp-(int)pesos[pos],pos+1);
        if (v1 != -1)v1+=valores[pos];
        long v2 = DP(pesoDisp,pos+1);
        long max = Math.max(v1,v2);
        memo[pesoDisp][pos] = max;
        visit[pesoDisp][pos] = true;
        return max;
    }

    public static void catalanS(){
        catalan[0]=1;
        catalan[1]=1;
        for (int i = 2; i < MOD+1; i++) {
            int n = i-1;
            long aux = (4*n+2)*invert(n+2)*catalan[n];
            catalan[i]=aux%MOD;
        }
    }

    public static long x=1,y=0;

    public static long euclid(long a, long b) {
        if (b!=0) {
            long d = euclid(b, a % b);
            long aux = y;
            y = x;
            x = aux;
            y -= a/b * x;
            return d;
        }
        x = 1;
        y = 0;
        return a;
    }

    public static long invert(long a) {
        euclid(a, MOD); // I'm just here for the side effects :)
        return ((x + MOD) % MOD);
    }
}
