import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        DColoredBoots solver = new DColoredBoots();
        solver.solve(1, in, out);
        out.close();
    }

    static class DColoredBoots {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] a = in.nextCharArray(n, 1);
            char[] b = in.nextCharArray(n, 1);
            ArrayList<Integer>[] A = new ArrayList[30];
            ArrayList<Integer>[] B = new ArrayList[30];
            ArrayList<Integer> sA = new ArrayList<>();
            ArrayList<Integer> sB = new ArrayList<>();
            for (int i = 0; i <= 29; i++) {
                A[i] = new ArrayList<>();
                B[i] = new ArrayList<>();
            }
            int cntA = 0, cntB = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == '?') {
                    cntA++;
                    sA.add(i);
                } else A[a[i] - 'a' + 1].add(i);
                if (b[i] == '?') {
                    cntB++;
                    sB.add(i);
                } else B[b[i] - 'a' + 1].add(i);
            }
            int tmpA = cntA, tmpB = cntB;
            int ans = 0;
            for (int i = 1; i <= 26; i++) {
                ans += MaxMin.Min(A[i].size(), B[i].size());
                if (A[i].size() > B[i].size()) {
                    ans += MaxMin.Min(A[i].size() - B[i].size(), cntB);
                    cntB -= MaxMin.Min(A[i].size() - B[i].size(), cntB);
                } else if (A[i].size() < B[i].size()) {
                    ans += MaxMin.Min(B[i].size() - A[i].size(), cntA);
                    cntA -= MaxMin.Min(B[i].size() - A[i].size(), cntA);
                }
            }
            int posA = 0;
            int posB = 0;
            out.println(ans + MaxMin.Min(cntA, cntB));
            for (int i = 1; i <= 26; i++) {
                for (int j = 0; j < MaxMin.Min(A[i].size(), B[i].size()); j++) {
                    out.println(A[i].get(j) + " " + B[i].get(j));
                }
                if (A[i].size() > B[i].size() && posB < sB.size()) {
                    for (int j = MaxMin.Min(A[i].size(), B[i].size()); j < A[i].size(); j++) {
                        out.println(A[i].get(j) + " " + sB.get(posB));
                        posB++;
                        if (posB >= sB.size()) break;
                    }
                } else if (A[i].size() < B[i].size() && posA < sA.size()) {
                    for (int j = MaxMin.Min(A[i].size(), B[i].size()); j < B[i].size(); j++) {
                        out.println(sA.get(posA) + " " + B[i].get(j));
                        posA++;
                        if (posA >= sA.size()) break;
                    }
                }
            }
            for (int i = posA; i < sA.size(); i++) {
                if (posB < sB.size()) {
                    out.println(sA.get(i) + " " + sB.get(posB));
                    posB++;
                } else return;
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

        public char[] nextCharArray(int length, int stIndex) {
            char[] arr = new char[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextCharacter();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
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