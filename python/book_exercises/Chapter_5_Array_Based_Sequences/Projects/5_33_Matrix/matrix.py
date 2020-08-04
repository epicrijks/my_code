class Matrix:
    """A class for a 2-dimensional Matrix."""
    def __init__(self, rows, columns):
        """Create a new Matrix.

        rows     the number of rows in the matrix
        columns  the number of columns in the matrix
        
        Elements are initialized to [0].
        """
        self._rows = rows
        self._columns = columns
        self._M = [[0] * columns for _ in range(rows)]

    def get_num_rows(self):
        """Returns number of rows in this Matrix."""
        return self._rows

    def get_num_cols(self):
        """Returns number of columns in this Matrix."""
        return self._columns

    def __getitem__(self, pos):
        r, c = pos
        if r < 0 or r > self._rows or c < 0 or c > self._columns:
            raise IndexError('index out of bounds')
        return self._M[r][c]

    def __add__(self, other):
        """Returns Matrix containing component-wise addition of this Matrix and other."""
        if not other.get_num_rows() == self._rows or other.get_num_cols() == self._columns:
            raise ValueError('matrices must have same dimensions')
        
        res = Matrix(self._rows, self._columns)
        for r in range(self._rows):
            for c in range(self._columns):
                res[r][c] = self._M[r][c] + other[r][c]
        return res 

    def __radd__(self, other):
        """Returns Matrix containing component-wise addition of this Matrix and other."""
        if not other.get_num_rows() == self._rows or other.get_num_cols() == self._columns:
            raise ValueError('matrices must have same dimensions')
        
        res = Matrix(self._rows, self._columns)
        for r in range(self._rows):
            for c in range(self._columns):
                res[r][c] = self._M[r][c] + other[r][c]
        return res 

    def __mul__(self, other):
        """Returns Matrix containing component-wise multiplication of this Matrix and other."""
        if other.get_num_rows() != self._rows or other.get_num_cols() != self._columns:
            raise ValueError('matrices must have same dimensions')
        
        res = Matrix(self._rows, self._columns)
        for r in range(self._rows):
            for c in range(self._columns):
                res[r][c] = self._M[r][c] * other[r][c]
        return res 

    def __rmul__(self, other):
        """Returns Matrix containing component-wise multiplication of this Matrix and other."""
        if not other.get_num_rows() == self._rows or other.get_num_cols() == self._columns:
            raise ValueError('matrices must have same dimensions')
        
        res = Matrix(self._rows, self._columns)
        for r in range(self._rows):
            for c in range(self._columns):
                res[r][c] = self._M[r][c] * other[r][c]
        return res

    def __str__(self):
        """Returns Matrix in list of list format."""
        return str([r for r in self._M])

    def insert(self, row, col, value):
        """Set value at [row][col] to value."""
        if row < 0 or row > self._rows or col < 0 or col > self._columns:
            raise IndexError('index out of bounds')
        temp = [r for r in self._M]
        temp[row][col] = value