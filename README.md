# FdF

This project is about creating a simple wireframe model representation of a 3D land-\
scape by linking various points (x, y, z) thanks to line segments (edges).


Your project must comply with the following rules:\
• You must use the MiniLibX. Either the version available on the school machines,\
or installing it using its sources.\
• You have to turn in a Makefile which will compile your source files. It must not\
relink.\
• Global variables are forbidden.\
Your program has to represent the model in isometric projection.\
cThe coordinates of the landscape are stored in a .fdf file passed as a parameter to\
your program. \
Each number represents a point in space:\
• The horizontal position corresponds to its axis.\
• The vertical position corresponds to its ordinate.\
• The value corresponds to its altitude.\
Remember to use of your libft the best way you can! Using get_next_line(),\
ft_split() and other functions will allow you to read data from the file in a quick and\
simple way.\
Keep in mind that the goal of this project is not to parse maps! However, this doesn’t\
mean that your program should crash when run. It means that we assume the map\
contained in the file is properly formatted.


V.2 Graphic management\
• Your program has to display the image in a window.\
• The management of your window must remain smooth (changing to another win-\
dow, minimizing, and so forth).\
• Pressing ESC must close the window and quit the program in a clean way.\
• Clicking on the cross on the window’s frame must close the window and quit the\
program in a clean way.\
• The use of the images of the MiniLibX is mandatory.
