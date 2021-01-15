class PairedMultiples:
    def selectedTotal(self, values, multiple):
        vis = set()
        for i, val in enumerate(values):
            if val in vis:
                continue
            for j in range(len(values)):
                if i == j:
                    continue
                if (val + values[j]) % multiple == 0:
                    vis.add(val)
                    vis.add(values[j])
                    break

        return sum(vis)