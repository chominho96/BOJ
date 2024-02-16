import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static final int MAX_SIZE = 1000010;
    private static BigInteger P;
    private static BigInteger K;
    private static boolean[] IS_PRIME = new boolean[MAX_SIZE];
    private static final Scanner scanner = new Scanner(System.in);

    private static void init() {
        for (int i = 2; i < MAX_SIZE; i++) IS_PRIME[i] = true;
        for (int i = 2; i * i < MAX_SIZE; i++) {
            if (!IS_PRIME[i]) continue;
            for (int j = i * i; j < MAX_SIZE; j += i) {
                IS_PRIME[j] = false;
            }
        }
    }

    private static void judge() {
        BigInteger div = BigInteger.valueOf(2);
        while (div.compareTo(K) < 0) {
            if (IS_PRIME[div.intValue()] && P.remainder(div).compareTo(BigInteger.valueOf(0)) == 0) {
                System.out.println("BAD " + div);
                return;
            }
            div = div.add(BigInteger.ONE);
        }
        System.out.println("GOOD");
    }

    public static void main(String[] args) {
        init();
        P = scanner.nextBigInteger();
        K = scanner.nextBigInteger();
        judge();
    }
}