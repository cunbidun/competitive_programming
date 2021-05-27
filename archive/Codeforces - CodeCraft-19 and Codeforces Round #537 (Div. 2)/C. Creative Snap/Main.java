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
        CCreativeSnap solver = new CCreativeSnap();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCreativeSnap {
        private int n;
        private int k;
        private long a;
        private long b;
        private int[] arr;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            a = in.nextLong();
            b = in.nextLong();
            arr = in.nextIntArray(k, 1);
            MergeSort.sort(arr, 1, k);
            out.println(cal(1, 1 << n));
        }

        private long cal(int l, int r) {
            int numL = BinarySearch.upperBound(arr, 1, k, l - 1) - 1;
            int numR = BinarySearch.upperBound(arr, 1, k, r) - 1;
            //  System.out.println(l + " " + r + " " + numL +  " " + numR);
            if (numL == numR) return a;
            if (l == r) return b * (numR - numL);
            int m = (l + r) >> 1;
            return MaxMin.Min(cal(l, m) + cal(m + 1, r), b * (numR - numL) * (r - l + 1));
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class BinarySearch {
        public static int upperBound(int[] array, int indexSt, int indexEn, int value) {
            int low = indexSt;
            int high = indexEn;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value >= array[mid]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (low == indexEn && array[low] <= value)
                return low + 1;
            return low;
        }

    }

    static class MergeSort {
        public static void sort(int[] list, int lowIndex, int highIndex) {
            if (lowIndex != highIndex) {
                int midIndex = (lowIndex + highIndex) / 2;
                sort(list, lowIndex, midIndex);
                sort(list, midIndex + 1, highIndex);
                merge(list, lowIndex, midIndex, highIndex);
            }
        }

        private static void merge(int[] list, int lowIndex, int midIndex, int highIndex) {
            int[] L = new int[midIndex - lowIndex + 2];
            if (midIndex + 1 - lowIndex >= 0)
                System.arraycopy(list, lowIndex, L, 0, midIndex + 1 - lowIndex);
            L[midIndex - lowIndex + 1] = Integer.MAX_VALUE;
            int[] R = new int[highIndex - midIndex + 1];
            for (int i = midIndex + 1; i <= highIndex; i++) R[i - midIndex - 1] = list[i];
            R[highIndex - midIndex] = Integer.MAX_VALUE;
            int i = 0, j = 0;
            for (int k = lowIndex; k <= highIndex; k++)
                if (L[i] <= R[j]) {
                    list[k] = L[i];
                    i++;
                } else {
                    list[k] = R[j];
                    j++;
                }
        }

    }
}