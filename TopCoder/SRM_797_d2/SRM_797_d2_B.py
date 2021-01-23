class OrganicChemistry:
    def countHydrogens(self, atoms, X, Y):
        deg_list = [0 for i in range(len(atoms))]
        for i in range(len(X)):
            deg_list[X[i]] += 1
            deg_list[Y[i]] += 1
        ans = 0
        for i,char in enumerate(atoms):
            correct_amount = 2
            if char == "N":
                correct_amount = 3
            elif char == "C":
                correct_amount = 4

            ans += max(0, correct_amount-deg_list[i])
        return ans