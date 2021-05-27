import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
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
        BArrayStabilization solver = new BArrayStabilization();
        solver.solve(1, in, out);
        out.close();
    }

    static class BArrayStabilization {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            QuickSort.sort(a, 1, n);
            out.print(MaxMin.Min(a[n - 1] - a[1], a[n] - a[2]));
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
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class QuickSort {
        public static int[] sort(int[] list, int lowIndex, int highIndex) {
            Arrays.sort(shuffleArray(list, lowIndex, highIndex), lowIndex, highIndex + 1);
            return list;
        }

        private static int[] shuffleArray(int[] arr, int lowIndex, int highIndex) {
            Random rnd = new Random();
            for (int i = lowIndex; i <= highIndex; i++) {
                int tmp = arr[i];
                int randomPos = i + rnd.nextInt(highIndex - i + 1);
                arr[i] = arr[randomPos];
                arr[randomPos] = tmp;
            }
            return arr;
        }

    }
}