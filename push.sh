set /p message = "Type here the push commentary"
git add *
git commit -m $(message)
git push
