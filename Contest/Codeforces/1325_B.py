if __name__ == "__main__":
    a = get(0, 1, 1)
    for i in a:
        print(len(set(i[1])))