import os
import base64
from pathlib import Path
import json 


file_path = "./up_load/"
file_list = os.listdir(file_path)

DEBUG =True


def _print(printItem):
    if(DEBUG):
        print(printItem)
        

for file in file_list :
    file_name = file[:file.index('.')]
    file_type = file[file.index('.'):]
    _print(file_name +" | "+ file_type)
    if ".wav" in file_type or ".svg" in file_type:
        with open(file_path + file,"rb") as f:
            #### Data procress encode to base64  
            base64_data = base64.b64encode(f.read())
            base64_data = base64_data.decode()
            # _print(base64_data)
            
            #### Write to html 
            b64_img_html = file_path + file_name + ".html"
            Path(b64_img_html).touch()
            if "svg" in file_type :
                src = '<img id="'+ file_name +'" src="data:image/svg+xml;base64, '+ base64_data + '"/>'
            else :
                src = '<audio id="' + file_name + ' src="data:audio/wav+xml;base64,'+ base64_data +'" />'
            html = open(b64_img_html, mode='w')
            html.write(src)
            html.close()
    elif ".json" in file_type :
        ### Read json
        proj_json = file_path + file
        input_file = open (proj_json)
        json_data = json.load(input_file)
        # _print(json_data)

class c_block :
    def __init__(self , id):
        self.id = id 
    def set_opcode(self , opcode) :
        self.opcode = opcode
    def set_parent_block(self , parent_block):
        self.parent_block = parent_block
    def set_next_block(self , next_block) :
        self.next_block = next_block
    def set_method(self , method):
        self.method = method
    def set_parameter(self , parameter) :
        self.parameter =parameter
        
    list_contant = []
    list_parameter = []
    
    list_para = []
    

L_block = []

i = 0


for blocks in json_data['targets'][1]['blocks']:
    blocks = str(blocks)
    _print(blocks)
    L_block.append(c_block(blocks))
    for block_contex in json_data['targets'][1]['blocks'][blocks] :
        block_contex = str(block_contex)
        context = str(json_data['targets'][1]['blocks'][blocks][block_contex]) 
        if  context != '\0' and '{' not in context :#and  'None' not in context 
            _print("  " + block_contex) 
            if "opcode" in context :
                L_block[i].set_opcode(context)
            elif "next" in context :
                L_block[i].set_next_block(context)
            elif "parent" in context :
                L_block[i].set_parent_block(context)
                
            ##### opcode next shadow ...
            contex_para = str(json_data['targets'][1]['blocks'][blocks][block_contex])
            _print("    " + contex_para)
            L_block[i].list_parameter.append(contex_para)
        elif '{' in context and '{}' not in context :
            for inner_context in json_data['targets'][1]['blocks'][blocks][block_contex] :
                inner_context = str(inner_context)
                L_block[i].list_contant.append(block_contex)
                _print("  " + block_contex)
                _print("    "  + inner_context)
                # for parameters in json_data['targets'][1]['blocks'][blocks][block_contex][inner_context] :
                    
                #     _print("      " + str(parameters))                    
                #     if "[" in str(parameters) and "]" in str(parameters) :
                #         L_block[i].parameter(str(parameters))
                #         for parameter in parameters :
                #             _print("        " + str(parameter))
    # print("\n")
    i += 1 

counter = i-1

# for id in range(0,counter) :
#     # print(id)
#     for contant in L_block[id].list_contant :
#         contant = str(contant)
#         if "opcode" in contant :
#             L_block[id].set_opcode(L_block[id].list_parameter[0])
#         elif "next" in contant :
#             L_block[id].set_next_block(L_block[id].list_parameter[1])
#         elif "parent" in contant :
#             L_block[id].set_parent_block(L_block[id].list_parameter[2])
#         elif "inputs" in contant :
#             L_block[id].set_method(L_block[id].list_parameter[3])
#         elif "[" in contant :
#             L_block[id].set_parameter(L_block[id].list_parameter[4])

# print("id  :  " + L_block[0].id)
# print("opcode  :  " + L_block[0].opcode)
# print("next_block  :  " + L_block[0].next_block)
# print("parent_block  :  " + L_block[0].parent_block)
# print("method  :  " + L_block[0].method)
# print("parameter  :  " + L_block[0].parameter)