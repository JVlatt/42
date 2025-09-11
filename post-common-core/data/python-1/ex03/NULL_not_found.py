def NULL_not_found(object: any) -> int:
	if object is None:
		print("Nothing :", object, type(object))
	elif isinstance(object, float) and object != object :
		print("Cheese :", object, type(object))
	elif type(object) is bool and object == False:
		print("Fake :", object, type(object))
	elif isinstance(object, int) and object == 0 :
		print("Zero :", object, type(object))
	elif isinstance(object, str) and object == "" :
		print("Empty :", type(object))
	else:
		print("Type not found")
		return 1
	return 0

