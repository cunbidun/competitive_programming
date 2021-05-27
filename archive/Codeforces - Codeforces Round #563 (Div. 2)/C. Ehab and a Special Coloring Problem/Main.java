import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CEhabAndASpecialColoringProblem solver = new CEhabAndASpecialColoringProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class CEhabAndASpecialColoringProblem {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int cur = 1;
            int[] ans = new int[n + 1];
            PrimeNumberAlgorithm gen = new PrimeNumberAlgorithm(100001);
            for (int dis = 2; dis <= n; dis++)
                if (gen.isPrime(dis)) {
                    for (int i = dis; i <= n; i += dis) {
                        ans[i] = cur;
                    }
                    cur++;
                }
            for (int i = 2; i <= n; i++) {
                out.print(ans[i] + " ");
            }
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class PrimeNumberAlgorithm {
        private int upperBound;
        private boolean[] isPrime;
        private ArrayList<Integer> primes = new ArrayList<>();

        public PrimeNumberAlgorithm(int upperBound) {
            this.upperBound = upperBound;
            isPrime = new boolean[upperBound + 1];
            sieve();
        }

        private void sieve() {
            Arrays.fill(isPrime, true);
            isPrime[0] = isPrime[1] = false;
            for (long i = 2; i <= upperBound; i++)
                if (isPrime[(int) i]) {
                    for (long j = i * i; j <= upperBound; j += i) isPrime[(int) j] = false;
                    primes.add((int) i);
                }
        }

        public boolean isPrime(int N) {
            if (N <= upperBound) return isPrime[N];
            for (Integer prime : primes) if (N % prime == 0) return false;
            return true;
        }

    }
}