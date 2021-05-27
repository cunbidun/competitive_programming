import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        CRoadToCinema solver = new CRoadToCinema();
        solver.solve(1, in, out);
        out.close();
    }

    static class CRoadToCinema {
        private int[] gas;
        private int k;
        private int s;
        private int t;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            k = in.nextInt();
            s = in.nextInt();
            t = in.nextInt();
            PairII[] car = new PairII[n + 1];
            for (int i = 1; i <= n; i++) {
                car[i] = new PairII(in.nextInt(), in.nextInt());
            }
            gas = in.nextIntArray(k, 1);

            Arrays.sort(car, 1, n + 1);
            MergeSort.sort(gas, 1, k);

            int[] maxGas = new int[n + 1];
            maxGas[1] = car[1].second;
            for (int i = 2; i <= n; i++) {
                maxGas[i] = MaxMin.Max(maxGas[i - 1], car[i].second);
            }
            int l = 1, r = n;
            while (l != r) {
                if (l == r - 1) {
                    if (!ch(maxGas[l])) l = r;
                    break;
                }
                int m = (l + r) >> 1;
                if (ch(maxGas[m])) r = m;
                else l = m + 1;
            }
            if (!ch(maxGas[l])) {
                out.println(-1);
                return;
            }
            out.println(car[l].first);
        }

        private boolean ch(int m) {
            int cur = 0;
            int time = 0;
            for (int i = 1; i <= k; i++) {
                int d = gas[i] - cur;
                if (d > m) return false;
                else if (m >= 2 * d) time += d;
                else {
                    int acc = m - d;
                    int nor = d - acc;
                    time += acc + nor * 2;
                }
                cur = gas[i];
            }
            int d = s - cur;
            if (d > m) return false;
            else if (m >= 2 * d) time += d;
            else {
                int acc = m - d;
                int nor = d - acc;
                time += acc + nor * 2;
            }
            return time <= t;
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
}