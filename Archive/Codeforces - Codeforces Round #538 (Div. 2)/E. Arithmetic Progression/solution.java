import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.concurrent.ThreadLocalRandom;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
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
        EArithmeticProgression solver = new EArithmeticProgression();
        solver.solve(1, in, out);
        out.close();
    }

    static class EArithmeticProgression {
        int used = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int l = 0, r = (int) 1e9;
            while (l != r) {
                if (l == r - 1) {
                    int tmp = askG(l, in, out);
                    if (tmp == -1) return;
                    if (tmp == 1) l = r;
                    break;
                }
                int m = (l + r) >> 1;
                int tmp = askG(m, in, out);
                if (tmp == -1) return;
                if (tmp == 1) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            used = 60 - used;
            ArrayList<Integer> num = new ArrayList<>();
            while (used-- > 0) {
                int tmp = askI((int) OneNumberGen.genInt(1, n), in, out);
                if (tmp == -1) break;
                num.add(tmp);
            }
            Collections.sort(num);
            int ans = 0;
            for (Integer num1 : num)
                for (Integer num2 : num)
                    ans = MathAlgorithm.gcd(Math.abs(num1 - num2), ans);
            // System.out.println("!!!" + n + " " + l);
            out.println("! " + (l - ans * (n - 1)) + " " + ans);
            out.flush();
        }

        private int askG(int m, InputReader in, PrintWriter out) {
            used++;
            out.println("> " + m);
            out.flush();
            return in.nextInt();
        }

        private int askI(int i, InputReader in, PrintWriter out) {
            out.println("? " + i);
            out.flush();
            return in.nextInt();
        }

    }

    static class OneNumberGen {
        private static long genI(long min, long max) {
            return ThreadLocalRandom.current().nextLong(min, max + 1);
        }

        public static long genInt(long min, long max) {
            if (min >= 0)
                return (genI(min, max));
            else if (max >= 0) {
                double ratio = (double) Math.abs(min) / (Math.abs(min) + max);
                ratio *= 1000000000000000000D;
                double prob = (double) (OneNumberGen.genInt(1, 1000000000000000000L));
                if (Double.compare(ratio, prob) > 0) {
                    return -(genI(0, -min));
                } else {
                    return (genI(0, max));
                }
            } else
                return -(OneNumberGen.genI(-min, -max));
        }

    }

    static class MathAlgorithm {
        public static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
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
}