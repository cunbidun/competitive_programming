import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        Task1260D solver = new Task1260D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1260D {
        private InputReader in;
        private OutputWriter out;
        int t;
        int k;
        int n;
        int[] d;
        ArrayList<PairII>[] mines;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int m = in.nextInt();
            n = in.nextInt();
            k = in.nextInt();
            t = in.nextInt();
            d = in.nextIntArray(m, 1);
            mines = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) mines[i] = new ArrayList<>();
            for (int i = 1; i <= k; i++) mines[in.nextInt()].add(new PairII(in.nextInt(), in.nextInt()));
            MergeSort.sort(d, 1, m, Comparator.reverseOrder());
            int l = 0, r = m;
            while (l != r) {
                if (l == r - 1) {
                    if (ch(r)) l = r;
                    break;
                }
                int mid = (l + r) >> 1;
                if (ch(mid)) l = mid;
                else r = mid - 1;
            }
            out.println(l);
        }

        private boolean ch(int id) {
            if (id == 0) return true;
            int val = d[id];
            int time = 0;
            int cleared = 0;
            for (int i = 1; i <= n; i++) {
                for (PairII p : mines[i]) {
                    if (p.second > val) {
                        if (p.first <= cleared) continue;
                        int toGo = p.first;
                        for (int j = i; j <= toGo; j++)
                            for (PairII pp : mines[j])
                                if (pp.second > val)
                                    toGo = MaxMin.Max(toGo, pp.first);
                        cleared = MaxMin.Max(cleared, toGo);
                        time += 2 * (toGo - i + 1);
                    }
                }
                time++;
            }
//        out.println(cleared);
//        out.println(time + 1);
            return time + 1 <= t;
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

    static class MergeSort {
        private static final int CUTOFF = 7;

        private MergeSort() {
        }

        private static void swap(Object[] a, int i, int j) {
            Object swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }

        private static boolean less(Object a, Object b, Comparator comparator) {
            return comparator.compare(a, b) < 0;
        }

        private static void merge(Object[] src, Object[] dst, int lo, int mid, int hi, Comparator comparator) {
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; k++) {
                if (i > mid) dst[k] = src[j++];
                else if (j > hi) dst[k] = src[i++];
                else if (less(src[j], src[i], comparator)) dst[k] = src[j++];
                else dst[k] = src[i++];
            }
        }

        private static void sort(Object[] src, Object[] dst, int lo, int hi, Comparator comparator) {
            if (hi <= lo + CUTOFF) {
                insertionSort(dst, lo, hi, comparator);
                return;
            }
            int mid = lo + (hi - lo) / 2;
            sort(dst, src, lo, mid, comparator);
            sort(dst, src, mid + 1, hi, comparator);
            if (!less(src[mid + 1], src[mid], comparator)) {
                System.arraycopy(src, lo, dst, lo, hi - lo + 1);
                return;
            }

            merge(src, dst, lo, mid, hi, comparator);
        }

        private static void insertionSort(Object[] a, int lo, int hi, Comparator comparator) {
            for (int i = lo; i <= hi; i++)
                for (int j = i; j > lo && less(a[j], a[j - 1], comparator); j--)
                    swap(a, j, j - 1);
        }

        public static void sort(Object[] a, int lo, int hi, Comparator comparator) {
            Object[] aux = a.clone();
            sort(aux, a, lo, hi, comparator);
        }

        public static int[] sort(int[] input, int lo, int hi, Comparator comparator) {
            Integer[] a = new Integer[input.length];
            for (int ctr = 0; ctr < input.length; ctr++) a[ctr] = input[ctr];
            sort(a, lo, hi, comparator);
            for (int ctr = 0; ctr < a.length; ctr++) input[ctr] = a[ctr];
            return input;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }

    static class PairII implements Comparable<PairII> {
        public int first;
        public int second;

        public PairII(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairII pair = (PairII) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }
}