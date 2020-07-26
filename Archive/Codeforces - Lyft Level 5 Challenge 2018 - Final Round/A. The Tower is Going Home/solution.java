import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;
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
        ATheTowerIsGoingHome solver = new ATheTowerIsGoingHome();
        solver.solve(1, in, out);
        out.close();
    }

    static class ATheTowerIsGoingHome {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            if (m == 0) {
                out.println(0);
                return;
            }
            int[] ver = in.nextIntArray(n, 1);
            ArrayList<Integer> h = new ArrayList<>();
            TripIII[] inp = new TripIII[m + 1];
            for (int i = 1; i <= m; i++) {
                int l = in.nextInt();
                int r = in.nextInt();
                int y = in.nextInt();
                inp[i] = new TripIII(y, l, r);
            }
            Arrays.sort(inp, 1, m);
            for (int i = 1; i <= m; i++) {
                int cur = inp[i].first;
                if (inp[i].second == 1) {
                    int r = inp[i].third;
                    for (int j = i + 1; j <= m; j++) {
                        if (cur == inp[j].first) {
                            if (inp[j].second == inp[j - 1].third + 1) {
                                r = inp[j].third;
                            } else {
                                i = j - 1;
                                break;
                            }
                        } else {
                            i = j - 1;
                            break;
                        }
                    }
                    h.add(r);
                }
            }
            Collections.sort(h);
            m = h.size();
            if (m == 0) {
                out.println(0);
                return;
            }
            if (n == 0) {
                out.println(m - (BinarySearch.lowerBound(h, 0, h.size() - 1, 1000000000)));
                return;
            }
            MergeSort.sort(ver, 1, n);
            //out.println((BinarySearch.lowerBound(h, 0, h.size() - 1, 4)));
            int ans = m;
            for (int i = 0; i <= n; i++) {
                int exH;
                if (i == n)
                    exH = m - (BinarySearch.lowerBound(h, 0, h.size() - 1, 1000000000));
                else
                    exH = m - (BinarySearch.lowerBound(h, 0, h.size() - 1, ver[i + 1]));
                ans = MaxMin.Min(ans, i + exH);
            }
            out.println(ans);
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

    static class BinarySearch {
        public static int lowerBound(ArrayList<Integer> array, int indexSt, int indexEn, long value) {
            if (value > array.get(indexEn)) return indexEn + 1;
            int low = indexSt;
            int high = indexEn;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value <= array.get(mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }

    }

    static class TripIII implements Comparable<TripIII> {
        public int first;
        public int second;
        public int third;

        public TripIII(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            TripIII trip = (TripIII) o;

            return first == trip.first && second == trip.second && third == trip.third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

        public int compareTo(TripIII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            return Integer.compare(third, o.third);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}