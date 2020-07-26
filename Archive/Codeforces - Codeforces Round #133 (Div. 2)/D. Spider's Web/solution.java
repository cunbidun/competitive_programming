import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task216D solver = new Task216D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task216D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            ArrayList<Integer> list = new ArrayList<>();
            int[][] thread = new int[n + 1][];
            TreeSet<Integer> set = new TreeSet<>();

            int cnt = 0;

            for (int i = 1; i <= n; i++) {
                int k = in.nextInt();
                thread[i] = new int[k + 1];
                thread[i][0] = k;
                for (int j = 1; j <= k; j++) {
                    int x = in.nextInt();
                    thread[i][j] = x;
                    if (!set.contains(x)) {
                        set.add(x);
                        list.add(x);
                        cnt++;
                    }
                }
                QuickSort.sort(thread[i], 1, k);
            }

            int[] pos = new int[(int) 1e5 + 1];
            Collections.sort(list);
            for (int i = 0; i < list.size(); i++) {
                pos[list.get(i)] = i + 1;
            }

            set.clear();
            list.clear();

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= thread[i][0]; j++) {
                    thread[i][j] = pos[thread[i][j]];
                }
            }

            FTSum[] ft = new FTSum[n + 1];
            ft[n] = new FTSum(MaxMin.Max(thread[n][thread[n][0]], thread[1][thread[1][0]]));

            for (int j = 1; j <= thread[1][0]; j++) {
                ft[n].update(thread[1][j], 1);
            }
            for (int j = 1; j <= thread[n][0]; j++) {
                ft[n].update(thread[n][j], 1);
            }
            int ans = 0;

            for (int i = 1; i < n; i++) {
                ft[i] = new FTSum(MaxMin.Max(thread[i][thread[i][0]], thread[i + 1][thread[i + 1][0]]));
                for (int j = 1; j <= thread[i][0]; j++) {
                    ft[i].update(thread[i][j], 1);
                }
                for (int j = 1; j <= thread[i + 1][0]; j++) {
                    ft[i].update(thread[i + 1][j], 1);
                }
                if (i > 1) {
                    for (int j = 2; j <= thread[i][0]; j++) {
                        if (ft[i - 1].getSum(thread[i][j - 1], thread[i][j]) != ft[i].getSum(thread[i][j - 1], thread[i][j]))
                            ans++;
                    }
                    if (i > 2) ft[i - 1].clear();
                }
            }

            for (int j = 2; j <= thread[1][0]; j++) {
                if (ft[1].getSum(thread[1][j - 1], thread[1][j]) != ft[n].getSum(thread[1][j - 1], thread[1][j]))
                    ans++;
            }
            for (int j = 2; j <= thread[n][0]; j++) {
                if (ft[n - 1].getSum(thread[n][j - 1], thread[n][j]) != ft[n].getSum(thread[n][j - 1], thread[n][j]))
                    ans++;
            }
//        for (int i = 2; i <= n; i++) {
//            for (int j = 2; j <= thread[i][0]; j++) {
//                if (ft[i - 1].getSum(thread[i][j - 1], thread[i][j]) != ft[i].getSum(thread[i][j - 1], thread[i][j]))
//                    ans++;
//            }
//        }
            out.println(ans);
        }

    }

    static class QuickSort {
        public static void sort(int[] list, int lowIndex, int highIndex) {
            ArrayUtils.shuffleArray(list, lowIndex, highIndex);
            Arrays.sort(list, lowIndex, highIndex + 1);
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

    static class FTSum {
        private int n;
        private int[] sum;

        public FTSum(int n) {
            sum = new int[n + 1];
            this.n = n;
        }

        public void update(int pos, int val) {
            while (pos <= n) {
                sum[pos] += val;
                pos += pos & -pos;
            }
        }

        public int getSum(int pos) {
            int ans = 0;
            while (pos != 0) {
                ans += sum[pos];
                pos -= pos & -pos;
            }
            return ans;
        }

        public int getSum(int l, int r) {
            return getSum(r) - getSum(l - 1);
        }

        public void clear() {
            sum = null;
            n = 0;
        }

    }

    static class ArrayUtils {
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }
}