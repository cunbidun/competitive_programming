import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CNastyaIsTransposingMatrices solver = new CNastyaIsTransposingMatrices();
        solver.solve(1, in, out);
        out.close();
    }

    static class CNastyaIsTransposingMatrices {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[510][510];
            int[][] b = new int[510][510];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    a[i][j] = in.nextInt();
                }
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    b[i][j] = in.nextInt();
                }
            }

            ArrayList<Integer>[] A = new ArrayList[510];
            ArrayList<Integer>[] B = new ArrayList[510];

            for (int i = 0; i <= 505; i++) A[i] = new ArrayList<>();
            for (int i = 0; i <= 505; i++) B[i] = new ArrayList<>();

            for (int i = 1; i <= m; i++) {
                int cur = 1;
                for (int j = i; j >= 1; j--) {
                    A[i].add(a[cur][j]);
                    cur++;
                    if (cur > n) break;
                }
                cur = 1;
                for (int j = i; j >= 1; j--) {
                    B[i].add(b[cur][j]);
                    cur++;
                    if (cur > n) break;
                }
                if (A[i].size() != B[i].size()) {
                    out.println("NO");
                    return;
                }
                Collections.sort(A[i]);
                Collections.sort(B[i]);

                for (int j = 0; j < A[i].size(); j++) {
                    if (!A[i].get(j).equals(B[i].get(j))) {
                        out.println("NO");
                        return;
                    }
                }
            }

            A = new ArrayList[510];
            B = new ArrayList[510];
            for (int i = 0; i <= 505; i++) A[i] = new ArrayList<>();
            for (int i = 0; i <= 505; i++) B[i] = new ArrayList<>();

            for (int i = 1; i <= n; i++) {
                int cur = m;
                for (int j = i; j <= n; j++) {
                    A[i].add(a[j][cur]);
                    cur--;
                    if (cur <= 0) break;
                }
                cur = m;
                for (int j = i; j <= n; j++) {
                    B[i].add(b[j][cur]);
                    cur--;
                    if (cur <= 0) break;
                }
                if (A[i].size() != B[i].size()) {
                    out.println("NO");
                    return;
                }
                Collections.sort(A[i]);
                Collections.sort(B[i]);

                for (int j = 0; j < A[i].size(); j++) {
                    if (!A[i].get(j).equals(B[i].get(j))) {
                        out.println("NO");
                        return;
                    }
                }
            }
            out.println("YES");
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}