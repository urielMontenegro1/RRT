# RRT

![tree_267376982](https://user-images.githubusercontent.com/77483327/236960320-728a6d9e-f081-44f9-9908-ada10b0f2f61.jpg)


Rapidly-exploring random tree or RRT is a algorithm which is used for mobile robots, it can used in ESP32, for finding a path to follow by a random points seted.

to use is necessary to create an object:

![image](https://github.com/urielMontenegro1/RRT/assets/77483327/3e7080b3-caf8-4752-b4a3-46544f83bce4)

then after configure your RRT object, the reason to  put that while is because inside from the loop function could reinitiate the process of the algorithm:

![image](https://github.com/urielMontenegro1/RRT/assets/77483327/fc13f61f-9be8-498a-9a14-5b498e3abdd2)

"ruta.getStatus()" that fuction is for the while if the algorithm finds a rute or path to follow, the while loop stops.

To show the nodes that the algorithm has created, use for:

![image](https://github.com/urielMontenegro1/RRT/assets/77483327/d909ecd8-03b8-43a7-8142-e3c0fe9dc95f)






actually this code is uder "codestruction", maybe it coud be a headache to prove in your system.
