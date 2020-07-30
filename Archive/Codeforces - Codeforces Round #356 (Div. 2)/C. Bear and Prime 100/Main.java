import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

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
        CBearAndPrime100 solver = new CBearAndPrime100();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBearAndPrime100 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            ArrayList<Integer> list = new ArrayList<>();

            PrimeNumberAlgorithm gen = new PrimeNumberAlgorithm(150);
            for (int i = 2; i <= 100; i++) {
                list.add(i);
            }
            boolean isPrime = true;
            int cnt = 0;
            for (int i = 2; i <= 30; i++) {
                if (gen.isPrime(i)) {
                    if (ask(in, out, i)) {
                        isPrime = false;
                        cnt++;
                        for (int j = 0; j < list.size(); j++) {
                            if (list.get(j) % i != 0) {
                                list.remove(j);
                                j--;
                            }
                        }
                    } else {
                        for (int j = 0; j < list.size(); j++) {
                            if (list.get(j) % i == 0) {
                                list.remove(j);
                                j--;
                            }
                        }
                    }
                }
            }
            if (cnt >= 2) {
                ans(out, "composite");
                return;
            }
            if (isPrime) {
                ans(out, "prime");
                return;
            }
            for (int i = 1; i < list.size(); i++) {
                if (gen.isPrime(list.get(i))) {
                    ans(out, "composite");
                    return;
                } else {
                    if (ask(in, out, list.get(i))) {
                        ans(out, "composite");
                        return;
                    }
                }
            }
            ans(out, "prime");
        }

        private void ans(PrintWriter out, String tmp) {
            out.println(tmp);
            out.flush();
        }

        private boolean ask(InputReader in, PrintWriter out, int i) {
            out.println(i);
            out.flush();
            String ans = in.nextString();
            return ans.equals("yes");
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}