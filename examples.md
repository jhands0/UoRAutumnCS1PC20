# Project Manager tool usage examples

## Scenarios

### create_project

>>>
Pre:  In a folder with a file called myproject already in it

```
$ pm create_project myproject
A folder of that name already exists.  Aborting.
```

Post: No change
>>>
---
>>>
Pre:  In a folder with a folder called myproject already in it

```
$ pm create_project myproject
A folder of that name already exists.  Aborting.
```

Post: No change
>>>
---
>>>
Pre: In a folder which does not have a pre-existing file or folder called myproject.
  For example, in /home/pat/cw2

```
$ pm create_project myproject
Initialized empty Git repository in /home/pat/cw2/myproject/.git/
```

Post: A new folder called myproject exists in current directory.  An ls -al myproject returns:

```
total 0
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 .
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 ..
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 .git
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 bin
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 docs
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 lib
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 src
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 tests
```
>>>
---
>>>
Pre: In a folder which does not have a pre-existing file or folder called myproject.
  For example, in /home/pat/cw2

```
$ pm create_project mypro ject
Wrong number of parameters, should be pm command arg
```

Post: No change
>>>
---
>>>
Pre: In a folder which does not have a pre-existing file or folder called myproject.
  For example, in /home/pat/cw2

```
$ pm create_project "mypro ject"
Bad characters in folder name
```
Post: No change
>>>
---

### add_feature
>>>
Pre:  In a folder with a folder called myproject already in it

```
$ pm add_feature feature1 
A folder of that name already exists.  Aborting.
```

Post: No change
>>>
---
>>>
Pre: In a folder which does not have a pre-existing file or folder called feature1.
  For example, in /home/pat/cw2/myproject

```
$ pm add_feature feature1

```

Post: A new folder called feature1 exists in current directory.  An ls -al feature1 returns:
```
total 0
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 .
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 ..
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 bin
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 docs
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 lib
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 src
drwxr-xr-x 1 pat pat 4096 Nov 14 13:00 tests
```
and git branch should report
feature1
master
>>>
---
### add_tag

>>>

Pre: In a folder created by add_feature called feature1 which does not have a file called .pm_tag in it.  For example, in /home/pat/cw2/project/feature1

```
$ pm add_tag F1
```
Post: A new file called .pm_tag exists in current directory, whose contents are the tag applied.  e.g. cat .pm_tag should return:
F1


>>>
---
>>>
Pre: In a folder created by add_feature called feature1 which does have a file called .pm_tag in it.  For example, in /home/pat/cw2/project/feature1/.pm_tag

```
$ pm add_tag F4
Already a tag for this folder
F1
```
Post: A new file called .pm_tag exists in current directory, whose contents are the tag applied.  e.g. cat .pm_tag should return:
F1
>>>
---

### find_tag
>>>
Pre: In a folder which has subfolders, one, two and three.  Subfolder one has subfolders first and last.  Folder one has a .pm_tag with contents F1, folder three has a .pm_tag with contents F3, and one/first has a .pm_tag with contents F1.1
```
$ pm find_tag F1
./one
```
Post: No change

Pre: In a folder which has subfolders, one, two and three.  Subfolder one has subfolders first and last.  Folder one has a .pm_tag with contents F1, folder three has a .pm_tag with contents F3, and one/first has a .pm_tag with contents F1.1
```
$ pm find_tag F1.1
./one/first
```
Post: No change
>>>
---
### move_by_tag
>>>
Pre: In a folder which has subfolders, one, two and three.  Subfolder one has subfolders first and last.  Folder one has a .pm_tag with contents F1, folder three has a .pm_tag with contents F3, and one/first has a .pm_tag with contents F1.1
```
$  pm move_by_tag F3 F1
```

Post: folder which relates to tag F3 (three in this case) should have moved from current folder (or whereever else it was...) to the folder related to F1 (one in this case)
>>>
---
### output_svg
>>>
Pre: In parent folder of project (for example in /home/pat/cw2 in this case).  
```
$ pm output_svg myproject
```

Post: folder has a new file which is in plantuml wbs format, and a new .svg file created from it, and which does not list .git, bin, docs, lib, src or tests folders .  e.g.
```
@startwbs
* myproject
** feature1
** one
*** first
*** last
** three
** two
@endwbs
```
![folder tree](tree.svg "Image of folder tree")
>>>
