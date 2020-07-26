import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
        CBullsAndCows solver = new CBullsAndCows();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBullsAndCows {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int a[] = new int[n + 1];
            int b[] = new int[n + 1];
            int c[] = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
                c[i] = in.nextInt();
            }
            ArrayList<String> list = new ArrayList<>();
            for (int i = 100; i <= 9999; i++) {
                boolean f = false;
                String si = Integer.toString(i);
                if (i < 1000) si = '0' + si;
                for (int ii = 0; ii < si.length(); ii++)
                    for (int jj = 0; jj < si.length(); jj++)
                        if (jj != ii) {
                            if (si.charAt(jj) == si.charAt(ii)) f = true;
                        }
                if (f) continue;
                f = false;
                for (int j = 1; j <= n; j++) {
                    String sj = Integer.toString(a[j]);
                    if (a[j] < 1000) sj = '0' + sj;
                    int cntB = 0;
                    TreeSet<Integer> tree = new TreeSet<>();
                    for (int k = 0; k <= 3; k++) {
                        if (si.charAt(k) == sj.charAt(k)) cntB++;
                        else {
                            tree.add(si.charAt(k) - '0');
                            tree.add(sj.charAt(k) - '0');
                        }
                    }
                    if (!(cntB == b[j] && 8 - tree.size() - cntB * 2 == c[j])) f = true;
                }
                if (!f) list.add(si);
            }
            if (list.size() > 1) out.println("Need more data");
            else if (list.size() == 0) out.println("Incorrect data");
            else out.println(list.get(0));
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