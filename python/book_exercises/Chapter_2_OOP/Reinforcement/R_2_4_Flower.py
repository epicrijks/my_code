class Flower:
    """A class for a flower."""
    
    def __init__(self, name, numPetals, price):
        """Create a new instance of a Flower.

        name        the name of the flower.
        numPetals   how many petals are normally found on this flower.
        price       the cost of one of these flowers.
        """
        self._name = name
        self._petals = numPetals
        self._price = price

    def get_name(self):
        """Returns name of flower."""
        return self._name

    def get_num_petals(self):
        """Returns number of petals on flower."""
        return self._petals

    def get_price(self):
        """Returns price of flower."""
        return self._price

    def set_name(self, name):
        """Sets name of flower to name."""
        self._name = str(name)

    def set_num_pets(self, n):
        """Sets number of petals to n."""
        self._petals = int(n)

    def set_price(self, price):
        self._price = float(price)

