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
import java.util.TreeMap;
import java.util.Map;
import java.util.concurrent.ThreadLocalRandom;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        DTokitsukazeCSLAndStoneGame solver = new DTokitsukazeCSLAndStoneGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTokitsukazeCSLAndStoneGame {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            QuickSort.sort(a, 1, n);
            long ans = 0;
            TreeSet<Integer> set = new TreeSet<>();
            PositiveCounter<Integer> cnt = new PositiveCounter<>();
            for (int i = 1; i <= n; i++) {
                set.add(a[i]);
                cnt.increase(a[i], 1);
                ans += a[i] - i + 1;
            }
            boolean[] needMove = new boolean[n + 1];
            boolean[] cantMove = new boolean[n + 1];
            int cntNeed = 0;
            int cntCant = 0;
            for (int i = 1; i <= n; i++) {
                int tmp = cnt.get(a[i]);
                if (tmp >= 3) {
                    out.println("cslnb");
                    return;
                }
                if (tmp == 2) {
                    needMove[i] = true;
                    cntNeed++;
                }
                if (set.contains(a[i] - 1) || a[i] == 0) {
                    cntCant++;
                    cantMove[i] = true;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (needMove[i] && cantMove[i]) {
                    out.println("cslnb");
                    return;
                }
            }
            cntNeed /= 2;
            if (cntNeed >= 2 || cntCant == n || ans % 2 == 0)
                out.println("cslnb");
            else out.println("sjfnb");
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

        public void println(String i) {
            out.println(i);
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

    static class PositiveCounter<T extends Comparable<T>> {
        private TreeMap<T, Integer> map = new TreeMap<>();

        public PositiveCounter() {
        }

        public void increase(T key, int cnt) {
            map.merge(key, cnt, Integer::sum);
        }

        public int get(T key) {
            return map.getOrDefault(key, 0);
        }

    }

    static class QuickSort {
        public static void sort(int[] list, int lowIndex, int highIndex) {
            ArrayUtils.shuffleArray(list, lowIndex, highIndex);
            Arrays.sort(list, lowIndex, highIndex + 1);
        }

    }
}