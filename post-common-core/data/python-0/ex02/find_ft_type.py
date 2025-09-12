def all_thing_is_obj(object: any) -> int:
    if type(object) is list:
        print("List :", type(object))
    elif type(object) is tuple:
        print("Tuple :", type(object))
    elif type(object) is set:
        print("Set :", type(object))
    elif type(object) is dict:
        print("Dict :", type(object))
    elif type(object) is str:
        print(object, "is in the kitchen :", type(object))
    else:
        print("Type not found")
    return 42
