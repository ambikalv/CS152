#ifndef WARMUP5_H
#define WARMUP5_H


#ifndef STRUCT_DEFS
#define STRUCT_DEFS
typedef struct {
	unsigned int allocated_size;
	int *array;
} int_vector;
typedef struct {
	unsigned int red;
	unsigned int green;
	unsigned int blue;
} pixel;
#endif

char *safe_str_concat(char *str1, char *str2);
int_vector* make_init_array();
void write_value(int_vector *vector, unsigned int index, int value);
int read_value(int_vector *vector, unsigned int index);
pixel** make_and_init_image(int height, int width, pixel color);


#endif
