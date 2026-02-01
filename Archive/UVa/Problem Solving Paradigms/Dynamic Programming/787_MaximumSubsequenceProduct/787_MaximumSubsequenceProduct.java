import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int[] arr = new int[101];
        int size = 0;
        while(cin.hasNext())
        {
            int temp = cin.nextInt();
            if (temp != -999999)
                arr[size++] = temp;
            else
            {
                BigInteger max = BigInteger.valueOf(-2000000000);
                BigInteger acc = BigInteger.valueOf(1);
                for (int i = 0; i < size; i++)
                {
                    acc = BigInteger.valueOf(1);
                    for (int j = i; j < size; j++)
                    {
                        acc = acc.multiply(BigInteger.valueOf(arr[j]));
                        if (max.compareTo(acc) < 0)
                            max = acc;
                    }
                }
                System.out.println(max.toString());
                size = 0;
            }
        }
    }
}