import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        PrintWriter out = new PrintWriter(outputStream);
        CIlyaAndMatrix solver = new CIlyaAndMatrix();
        solver.solve(1, in, out);
        out.close();
    }

    static class CIlyaAndMatrix {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.nextLongArray(n, 1);
            MergeSort.sort(a, 1, n, Collections.reverseOrder());
            int cur = 1;
            long ans = 0;
            while (cur <= n) {
                for (int i = 1; i <= cur; i++) ans += a[i];
                cur *= 4;
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public long[] nextLongArray(int length, int stIndex) {
            long[] arr = new long[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public static long[] sort(long[] input, int lo, int hi, Comparator comparator) {
            Long[] a = new Long[input.length];
            for (int ctr = 0; ctr < input.length; ctr++) a[ctr] = input[ctr];
            sort(a, lo, hi, comparator);
            for (int ctr = 0; ctr < a.length; ctr++) input[ctr] = a[ctr];
            return input;
        }

    }
}