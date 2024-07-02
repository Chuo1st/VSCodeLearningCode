import json

person_data = [{"何" : [12, "chinese"]}, {"陈" : [32, "american"]}]
json_person_data = json.dumps(person_data, ensure_ascii=False)
print(type(json_person_data))
print(json_person_data)