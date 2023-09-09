<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!--Stylesheet import-->
    <link rel="stylesheet" href="style.css">
    <!--Page title-->
    <title>the unnamed coffee - store</title>
</head>
<!--Header Nav Bar-->
<body>
    <!--Header Nav Bar-->
    <div id="header" class="main_nav">
        <!--Name-->
        <div class="title">
            <a class="title1">THE</a>
            <div>
                <a class="title2">UNNAMED</a>
                <a class="title2">COFFEE</a>
            </div>
        </div>
        <!--Links-->
        <div>
            <ul class="nav_links">
                <li><a  href="index.php">Home</a></li>
                <li><a  href="services.php">Services</a></li>
                <li><a  href="store.php">Store</a></li>
                <li><a  href="News Page.php">News</a></li>
                <li><a  href="about_us.php">About</a></li>
            </ul>
        </div>
        <!--Button-->
        <div>
            <input type="button" value="Contact Us" class="contact_button">
        </div>
    </div>
    <div class="container">

    <form action="">

        <div class="row">

            <div class="col">

                <h3 class="title">billing address</h3>

                <div class="inputBox">
                    <span>full name :</span>
                    <input type="text" placeholder="Edsnaths Payag">
                </div>
                <div class="inputBox">
                    <span>email :</span>
                    <input type="email" placeholder="EdsnathsPayag@example.com">
                </div>
                <div class="inputBox">
                    <span>address :</span>
                    <input type="text" placeholder="Across - Talamban Campus">
                </div>
                <div class="inputBox">
                    <span>city :</span>
                    <input type="text" placeholder="Talamban">
                </div>

                <div class="flex">
                    <div class="inputBox">
                        <span>state :</span>
                        <input type="text" placeholder="Cebu">
                    </div>
                    <div class="inputBox">
                        <span>zip code :</span>
                        <input type="text" placeholder="123 456">
                    </div>
                </div>

            </div>

            <div class="col">

                <h3 class="title">payment</h3>

                <div class="inputBox">
                    <span>cards accepted :</span>
                    <img src="src\card_img.png" alt="">
                </div>
                <div class="inputBox">
                    <span>name on card :</span>
                    <input type="text" placeholder="Edsnaths Payag">
                </div>
                <div class="inputBox">
                    <span>credit card number :</span>
                    <input type="number" placeholder="1111-2222-3333-4444">
                </div>
                <div class="inputBox">
                    <span>exp month :</span>
                    <input type="text" placeholder="january">
                </div>

                <div class="flex">
                    <div class="inputBox">
                        <span>exp year :</span>
                        <input type="number" placeholder="2022">
                    </div>
                    <div class="inputBox">
                        <span>CVV :</span>
                        <input type="text" placeholder="1234">
                    </div>
                </div>

            </div>
    
        </div>

        <input type="submit" value="proceed to checkout" class="submit-btn">

    </form>

</div>    
    
</body>
</html>