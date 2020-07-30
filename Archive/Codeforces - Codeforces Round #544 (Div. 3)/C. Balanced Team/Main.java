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
        CBalancedTeam solver = new CBalancedTeam();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBalancedTeam {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            MergeSort.sort(a, 1, n);
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int tmp = BinarySearch.upperBound(a, 1, n, a[i] + 5) - 1;
                ans = MaxMin.Max(tmp - i + 1, ans);
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
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

    static class BinarySearch {
        public static int upperBound(int[] array, int indexSt, int indexEn, int value) {
            if (value >= array[indexEn]) return indexEn + 1;
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
            return low;
        }

    }
}