from copy import deepcopy, copy

class Vector:
    def __init__(self, d):
        """Create a d-dimensional vector of zeros, or vector with given values."""
        if isinstance(d, int):
            self._coords = [0] * d
        else:
            self._coords = deepcopy(d)

    def __len__(self):
        """Return the dimension of the vector."""
        return len(self._coords)

    def __getitem__(self, j):
        """Return the jth coordinate of the vector."""
        return self._coords[j]

    def __setitem__(self, j, val):
        """Set jth coordinate of the vector to given value."""
        self._coords[j] = val

    def __add__(self, other):
        """Return sum of two vectors."""
        if len(self) != len(other):             # relies on __len__ method
            raise ValueError("dimensions must agree")
        result = Vector(len(self))              # start with vector of zeros
        for j in range(len(self)):
            result[j] = self[j] + other[j]
        return result

    def __eq__(self, other):
        """Return True if vector has the same coordinates as other."""
        return self._coords == other._coords

    def __ne__(self, other):
        """Return True is vector differs from other."""
        return not self == other            # relies on __eq__ method

    def __str__(self):
        """Produce string representation of vector."""
        return '<' + str(self._coords)[1:-1] + '>'  # adapt list representation

    def __sub__(self, other):
        """Returns this vector minus other."""
        if len(self) != len(other):             # relies on __len__ method
            raise ValueError("dimensions must agree")
        result = Vector(len(self))              # start with vector of zeros
        for j in range(len(self)):
            result[j] = self[j] - other[j]
        return result

    def __neg__(self):
        """Returns vector with negated values."""
        result = Vector(len(self))              # start with vector of zeros
        for j in range(len(self)):
            result[j] = -1 * self[j]
        return result

    def __mul__(self, f):
        """Returns vector scaled by factor f or dot product of this vector and f if f is a vector"""
        if isinstance(f, list):
            if len(self) != len(f):             # relies on __len__ method
                raise ValueError("dimensions must agree")
            result = 0
            for j in range(len(self)):
                result += self[j] * f[j]
        else:
            result = Vector(len(self))              # start with vector of zeros
            for j in range(len(self)):
                result[j] = f * self[j]
        return result

    def __rmul__(self, f):
        """Returns vector scaled by factor f."""
        result = Vector(len(self))              # start with vector of zeros
        for j in range(len(self)):
            result[j] = f * self[j]
        return result