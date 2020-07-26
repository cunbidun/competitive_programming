import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;
import java.util.InputMismatchException;
import java.io.IOException;
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
        CMemoryForArrays solver = new CMemoryForArrays();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMemoryForArrays {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] b = in.nextIntArray(m, 1);
            int[] cnt = new int[31];
            QuickSort.sort(b, 1, m);
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= 30; j++) {
                    if (((a[i] >> j) & 1) == 1) {
                        cnt[j]++;
                    }
                }
            }
//        for (int i = 0; i <= 2; i++) {
//            out.print(cnt[i] + " ");
//        }
//        out.println();
            int cur = 0;
            int ans = 0;
            for (int i = 1; i <= m; i++) {
                while (cnt[cur] == 0 || b[i] > cur) {
                    cur++;
                    if (cur == 31) {
                        out.println(ans);
                        return;
                    }
                }
                ans++;
                cnt[cur]--;
                while (cur >= b[i] && cur != 0) {
                    cur--;
                    cnt[cur]++;
                }
            }
            out.println(ans);
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class QuickSort {
        public static void sort(int[] list, int lowIndex, int highIndex) {
            ArrayAlgorithm.shuffleArray(list, lowIndex, highIndex);
            Arrays.sort(list, lowIndex, highIndex + 1);
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

    static class ArrayAlgorithm {
        public static void shuffleArray(int[] array, int stIndex, int enIndex) {
            for (int i = enIndex; i > stIndex; i--) {
                int index = (int) OneNumberGen.genInt(stIndex, i - 1);
                if (index != i) {
                    array[index] ^= array[i];
                    array[i] ^= array[index];
                    array[index] ^= array[i];
                }
            }
        }

    }
}