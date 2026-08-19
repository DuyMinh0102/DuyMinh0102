struct Seg2D {
  int n, m;
  vector<vector<int>> t;
  Seg2D(const vector<vector<int>> &g) {
    n = g.size(), m = g[0].size();
    t.assign(4 * n, vector<int>(4 * m, 0));
    build_x(1, 0, n - 1, g);
  }
  void build_y(int vx, int lx, int rx, int vy, int ly, int ry,
               const vector<vector<int>> &g) {
    if (ly == ry)
      t[vx][vy] = (lx == rx) ? g[lx][ly] : t[2 * vx][vy] + t[2 * vx + 1][vy];
    else {
      int my = (ly + ry) / 2;
      build_y(vx, lx, rx, 2 * vy, ly, my, g);
      build_y(vx, lx, rx, 2 * vy + 1, my + 1, ry, g);
      t[vx][vy] = t[vx][2 * vy] + t[vx][2 * vy + 1];
    }
  }
  void build_x(int vx, int lx, int rx, const vector<vector<int>> &g) {
    if (lx != rx) {
      int mx = (lx + rx) / 2;
      build_x(2 * vx, lx, mx, g);
      build_x(2 * vx + 1, mx + 1, rx, g);
    }
    build_y(vx, lx, rx, 1, 0, m - 1, g);
  }
  void upd_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y,
             int v) {
    if (ly == ry)
      t[vx][vy] = (lx == rx) ? v : t[2 * vx][vy] + t[2 * vx + 1][vy];
    else {
      int my = (ly + ry) / 2;
      if (y <= my)
        upd_y(vx, lx, rx, 2 * vy, ly, my, x, y, v);
      else
        upd_y(vx, lx, rx, 2 * vy + 1, my + 1, ry, x, y, v);
      t[vx][vy] = t[vx][2 * vy] + t[vx][2 * vy + 1];
    }
  }
  void upd_x(int vx, int lx, int rx, int x, int y, int v) {
    if (lx != rx) {
      int mx = (lx + rx) / 2;
      if (x <= mx)
        upd_x(2 * vx, lx, mx, x, y, v);
      else
        upd_x(2 * vx + 1, mx + 1, rx, x, y, v);
    }
    upd_y(vx, lx, rx, 1, 0, m - 1, x, y, v);
  }
  int q_y(int vx, int vy, int ly, int ry, int qly, int qry) const {
    if (qly > ry || qry < ly)
      return 0;
    if (qly <= ly && ry <= qry)
      return t[vx][vy];
    int my = (ly + ry) / 2;
    return q_y(vx, 2 * vy, ly, my, qly, qry) +
           q_y(vx, 2 * vy + 1, my + 1, ry, qly, qry);
  }
  int q_x(int vx, int lx, int rx, int qlx, int qrx, int qly, int qry) const {
    if (qlx > rx || qrx < lx)
      return 0;
    if (qlx <= lx && rx <= qrx)
      return q_y(vx, 1, 0, m - 1, qly, qry);
    int mx = (lx + rx) / 2;
    return q_x(2 * vx, lx, mx, qlx, qrx, qly, qry) +
           q_x(2 * vx + 1, mx + 1, rx, qlx, qrx, qly, qry);
  }
  void upd(int x, int y, int v) { upd_x(1, 0, n - 1, x, y, v); }
  int qry(int r1, int c1, int r2, int c2) const {
    return q_x(1, 0, n - 1, r1, r2, c1, c2);
  }
};
