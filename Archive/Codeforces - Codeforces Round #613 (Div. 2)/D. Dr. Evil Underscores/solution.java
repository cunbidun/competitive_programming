import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task1285D solver = new Task1285D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1285D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            Trie trie = new Trie();
            int[] a = in.nextIntArray(n, 1);
            for (int i = 1; i <= n; i++) {
                StringBuilder tmp = new StringBuilder(Integer.toString(a[i], 2));
                while (tmp.length() < 30) tmp.insert(0, "0");
                trie.add(tmp.toString());
            }
            out.println(trie.solve(trie.root, 29));
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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

    static class Trie {
        Node root;

        Trie() {
            this.root = new Node();
        }

        void add(String tmp) {
            Node cur = root;
            for (int i = 0; i < tmp.length(); i++) {
                int c = tmp.charAt(i) - '0';
                if (cur.link[c] == null) cur.link[c] = new Node();
                cur = cur.link[c];
            }
        }

        public int solve(Node node, int lvl) {
            if (node.link[1] == null && node.link[0] == null) return 0;
            int res = 0;
            if (node.link[1] != null && node.link[0] != null) {
                res += (1L << lvl);
                res += MaxMin.Min(solve(node.link[1], lvl - 1), solve(node.link[0], lvl - 1));
            } else {
                if (node.link[1] != null) res += solve(node.link[1], lvl - 1);
                if (node.link[0] != null) res += solve(node.link[0], lvl - 1);
            }
            return res;
        }

        class Node {
            Node[] link = new Node[2];

        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(int i) {
            out.println(i);
        }

    }
}