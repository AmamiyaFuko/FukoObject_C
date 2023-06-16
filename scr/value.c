//value
typedef struct value{
    void*   _data;
    char*   type;
    int     charaterType;
    void    (*init)             (struct value* self);
//  virtual (*getData)          (struct value self);
    void    (*changeData)       (struct value* self, void* data);
    char*   (*getType)          (struct value* self);
    int     (*get_charaterType) (struct value* self);
    void    (*changeType)       (struct value* self, char* type);
}value;

void    __init_value__(value* self, void* data, char* type){
    self->_data = data;
    self->type  = type;
}
void    __changeData_value__(value* self, void* data){
    self->_data = data;
}
char*   __getType_value__(value* self){
    return self->type;
}               
int     __get_charaterType_value__(value* self){
    return self->charaterType;
}              
void    __changeType_value__(value* self, void* data){
    self->type = data;
}

value* Value(){
    value* ptr = (value*)malloc(sizeof(value));
    ptr->init               = __init_value__;
    ptr->changeData         = __changeData_value__;
    ptr->getType            = __getType_value__;
    ptr->get_charaterType   = __get_charaterType_value__;
    ptr->changeType         = __changeType_value__;
    return ptr;
}