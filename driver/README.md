# dsaimpl Driver Implementations
## avl_int
After running the driver, to see the result of the driver
```bash
for file in out/avl_dot/*.dot; do dot -Tpng "$file" >> "$file.png"; done
open out/avl_dot/*.png
```
