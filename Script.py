import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

fig, ax = plt.subplots(figsize=(5,1))


cmap= mpl.cm.get_cmap('viridis',4)
new_cmap = cmap.colors
norm = mpl.colors.Normalize(vmin=0, vmax=10)

fig.colorbar(mpl.cm.ScalarMappable(norm=norm, cmap=cmap),
             cax=ax,
             orientation="horizontal",
             ticks = range(0,11,5), spacing="proportional",
        

)

print(cmap(np.linspace(0, 1,6)))
plt.show()
