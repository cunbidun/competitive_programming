import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task1178D solver = new Task1178D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1178D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            PrimeNumberAlgorithm gen = new PrimeNumberAlgorithm(10000);
            if (n == 4) {
                out.println("5\n" +
                        "1 2\n" +
                        "1 3\n" +
                        "2 3\n" +
                        "2 4\n" +
                        "3 4");
                return;
            }
            if (gen.isPrime(n)) {
                out.println(n);
                for (int i = 2; i <= n; i++) {
                    out.println(i + " " + (i - 1));
                }
                out.println(1 + " " + n);
                return;
            }
            for (int i = n + 1; i <= n + n / 2; i++) {
                if (gen.isPrime(i)) {
                    out.println(i);
                    int tmp = n / 2;
                    for (int j = 2; j <= tmp; j++) {
                        out.println(j + " " + (j - 1));
                    }
                    out.println(1 + " " + tmp);
                    tmp++;
                    for (int j = tmp + 1; j <= n; j++) {
                        out.println(j + " " + (j - 1));
                    }
                    out.println(tmp + " " + n);

                    int cur = 1;
                    for (int j = 1; j <= i - n; j++) {
                        out.println(cur + " " + tmp);
                        cur++;
                        tmp++;
                    }
                    return;
                }
            }
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

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(int i) {
            out.println(i);
        }

        public void println(String i) {
            out.println(i);
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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
}