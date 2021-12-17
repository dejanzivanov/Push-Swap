# Push-Swap

Project about sorting 2 stacks in minimal amount of steps.  
Algoritm used in this project was [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort).  
Number of actions per 100 arguments: 1084  
Number of actions per 500 arguments: 6781  
Enough to pass the project with little bit more above the minimum grade.
**![push_swap_mark](https://github.com/dejanzivanov/Push-Swap/blob/master/push_swap.png)**  
<br/>
Sorting 100 Arguments visualised  

![](https://github.com/dejanzivanov/Push-Swap/blob/master/100%20arguments.gif)  

Credits to: [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)

<br/>

<!-- HOW TO -->
# How to use this project



Make sure that you have [GCC](https://gcc.gnu.org/), [Ruby](https://www.ruby-lang.org/en/) and [Python](https://www.python.org/) installed  
If you do not here is how to install them:

Install Ruby:  
```
sudo apt-get intall ruby
```
Install Python:  
```
brew install python3
```
Install GCC:  
```
sudo apt update
```
```
sudo apt install build-essential
```
```
sudo apt-get install manpages-dev
```
```
gcc --version
```
That’s it. GCC is now installed on your system, and you can start using it.  
<br/>

Clone the repository:  
```
git clone https://github.com/dejanzivanov/Push-Swap.git
```
Change the directory:  
```
cd Push-Swap
```
Run the make command: 
```
make
```
Clone the visualize and move all the content of it, on the same level as push_swap executable:  
```
git clone https://github.com/o-reo/push_swap_visualizer.git
```
Change the current directory: 
```
cd push_swap_visualizer/
```
Move whole content of the folder 1 level up: 
```
mv * ../
```  
<br/>
Run the following command to see visualizer with 100 arguments:

```
python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
```  
<br/>
Run the following command to see visualizer with 500 arguments:

```
python3 pyviz.py `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
```  
