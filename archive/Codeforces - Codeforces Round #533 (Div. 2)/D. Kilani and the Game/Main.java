import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DKilaniAndTheGame solver = new DKilaniAndTheGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DKilaniAndTheGame {
        static final int MAXA = (int) 1e3 + 10;
        String[] a = new String[MAXA];
        int[] s = new int[MAXA];
        Queue<Integer[]> q = new LinkedList<>();
        ArrayList<Queue<Integer[]>> re = new ArrayList<>(11);
        int[][] ch = new int[MAXA][MAXA];
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        int n;
        int m;
        int p;
        int[] cnt = new int[MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            p = in.nextInt();
            for (int i = 1; i <= p; i++) {
                s[i] = in.nextInt();
            }
            for (int i = 0; i <= 10; i++) {
                Queue<Integer[]> tmp = new LinkedList<>();
                re.add(tmp);
            }
            for (int i = 1; i <= n; i++) {
                a[i] = "#" + in.next();
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i].charAt(j) != '.' && a[i].charAt(j) != '#') {
                        int l = a[i].charAt(j) - '0';
                        ch[i][j] = l;
                        re.get(l).add(new Integer[]{l, i, j, 1});
                    }
                    if (a[i].charAt(j) == '#') {
                        ch[i][j] = 99;
                    }
                }
            }
            while (true) {
                int cur = check();
                if (cur == 0) break;
                for (cur = 1; cur <= p; cur++) {
                    while (!re.get(cur).isEmpty()) {
                        q.add(re.get(cur).remove());
                    }
                    while (!q.isEmpty()) {
                        Integer[] tmp = q.remove();
                        int x = tmp[1];
                        int y = tmp[2];
                        int dis = tmp[3];
                        for (int l = 0; l < 4; l++) {
                            int xx = x + dx[l];
                            int yy = y + dy[l];
                            if (ok(xx, yy)) {
                                ch[xx][yy] = tmp[0];
                                if (dis < s[tmp[0]]) {
                                    q.add(new Integer[]{cur, xx, yy, dis + 1});
                                } else if (dis == s[tmp[0]]) {
                                    re.get(cur).add(new Integer[]{cur, xx, yy, 1});
                                }
                            }
                        }
                    }
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= m; j++) {
//                        out.print(ch[i][j] + " ");
//                    }
//                    out.println("");
//                }
//                out.println("");
                }
            }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    cnt[ch[i][j]]++;

            for (int i = 1; i <= p; i++) out.print(cnt[i] + " ");
        }

        private int check() {
            for (int i = 1; i <= p; i++) {
                if (!re.get(i).isEmpty()) return i;
            }
            return 0;
        }

        private boolean ok(int i, int j) {
            return i >= 1 && j >= 1 && i <= n && j <= m && ch[i][j] <= 0;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}