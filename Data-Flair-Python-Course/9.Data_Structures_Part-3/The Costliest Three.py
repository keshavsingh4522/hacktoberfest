def the_costliest_three(items):
    for item in [(item,price) for (item,price) in items.items() if price in sorted(items.values())[-3:]]:
        print(item)

