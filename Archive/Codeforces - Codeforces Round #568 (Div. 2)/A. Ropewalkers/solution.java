import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        ARopewalkers solver = new ARopewalkers();
        solver.solve(1, in, out);
        out.close();
    }

    static class ARopewalkers {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);
            int[] a = in.nextIntArray(3, 1);
            MergeSort.sort(a, 1, 3);
            int d = in.nextInt();
            int ans = 0;

            if (a[2] - d < a[1]) {
                ans += a[1] - (a[2] - d);
            }
            if (a[2] + d > a[3]) {
                ans += a[2] + d - a[3];

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

    static class MergeSort {
        private static final int CUTOFF = 7;

        private MergeSort() {
        }

        private static void merge(Comparable[] src, Comparable[] dst, int lo, int mid, int hi) {
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; k++) {
                if (i > mid) dst[k] = src[j++];
                else if (j > hi) dst[k] = src[i++];
                else if (less(src[j], src[i])) dst[k] = src[j++];   //
                else dst[k] = src[i++];
            }
        }

        private static void sort(Comparable[] src, Comparable[] dst, int lo, int hi) {
            if (hi <= lo + CUTOFF) {
                insertionSort(dst, lo, hi);
                return;
            }
            int mid = lo + (hi - lo) / 2;
            sort(dst, src, lo, mid);
            sort(dst, src, mid + 1, hi);
            if (!less(src[mid + 1], src[mid])) {
                System.arraycopy(src, lo, dst, lo, hi - lo + 1);
                return;
            }

            merge(src, dst, lo, mid, hi);
        }

        private static void insertionSort(Comparable[] a, int lo, int hi) {
            for (int i = lo; i <= hi; i++)
                for (int j = i; j > lo && less(a[j], a[j - 1]); j--)
                    swap(a, j, j - 1);
        }

        private static void swap(Object[] a, int i, int j) {
            Object swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }

        private static boolean less(Comparable a, Comparable b) {
            return a.compareTo(b) < 0;
        }

        public static void sort(Comparable[] a, int lo, int hi) {
            Comparable[] aux = a.clone();
            sort(aux, a, lo, hi);
        }

        public static int[] sort(int[] input, int lo, int hi) {
            Integer[] a = new Integer[input.length];
            for (int ctr = 0; ctr < input.length; ctr++) a[ctr] = input[ctr];
            sort(a, lo, hi);
            for (int ctr = 0; ctr < a.length; ctr++) input[ctr] = a[ctr];
            return input;
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

    }
}