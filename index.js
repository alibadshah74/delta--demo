const express=require("express");
const app=express();
const mongoose=require("mongoose");
const Listing = require("./models/listing.js");
const path = require("path");
const methodOverride = require("method-override");
const ejsMate = require("ejs-mate");
const wrapAsync = require("./utils/wrapAsync.js");
const ExpressError = require("./utils/ExpressError.js");
const {listingSchema} = require("./Schema.js");


const MONG_URL="mongodb://127.0.0.1:27017/newwander";

main().then(()=>{ // callback to database
    console.log("connected to DB")
}).catch(err =>{
    console.log(err);
});
async function main(){  //connect mongoose database
    await mongoose.connect(MONG_URL)
};

app.set("view engine","ejs");
app.set("views",path.join(__dirname, "views"));
app.use(express.urlencoded({extended:true})); //jo hamara data id ke pass araha hai woh params ho paye
app.use(methodOverride("_method"));
app.engine("ejs", ejsMate);
app.use(express.static(path.join(__dirname, "/public")));


//basic API
app.get("/",(req,res)=>{
    res.render("alwaan/index.ejs");
});

const validateListing = (req,res,next)=>{
    let {error} = listingSchema.validate(req.body);
    if(error){
        let errMsg = error.details.map((el)=> el.message).join(",");
        throw new ExpressError(404, errMsg)
    }else{
        next();
    }
}

//index Route
app.get("/listings",wrapAsync(async (req,res)=>{
    const allListings=await Listing.find({});   //"".then((res)={console.log(res)})"database se data ko console  ko pass karega 
        res.render("listings/index",{allListings}); //database se data ko find karega and index.ejs ko pass akrega and index.ejs /listings ko pass karega
}));

//create :New & Create Route. GET => /listings/new =>Form => submit => post => /listings route pe create ho jayega
//New Route
app.get("/listings/new",(req,res)=>{
    res.render("listings/new.ejs");
});

//show Route. CRUD ka read part hai
app.get("/listings/:id",wrapAsync(async(req,res)=>{
    let {id} = req.params; // id ko extract karne ke liye use kiye.
    const listing = await Listing.findById(id); // id ke basis pe data ko find karenge and show.ejs ko pass kar denge
    res.render("listings/show.ejs",{listing});
}));

//create Route
app.post("/listings", validateListing ,wrapAsync(async(req,res,next)=>{
         //let {title,description, image, price, countary, location}=req.body;
         const newListing= new Listing(req.body.listing);
         await newListing.save();
         res.redirect("/listings");
}));
// Update:Edit and Update Route . GET => /listing/:id/edit =>edit form(render) =>submit =>PUT => /listings/:id 
//Edit Route
app.get("/listings/:id/edit",wrapAsync(async(req,res)=>{
    let {id} = req.params; // id ko extract karne ke liye use kiye.
    const listing = await Listing.findById(id);
    res.render("listings/edit.ejs", {listing});
}));

// Update Route
app.put("/listings/:id", validateListing,wrapAsync(async (req, res) => {
    let { id } = req.params;
    await Listing.findByIdAndUpdate(id,{...req.body.listing});
    res.redirect(`/listings/${id}`);
}));

//Delete Route
app.delete("/listings/:id",wrapAsync(async (req,res)=>{
    let { id } = req.params;
    let deleteListing = await Listing.findByIdAndDelete(id);
    console.log(deleteListing);
    res.redirect("/listings");
}));

// app.get("/testListing", async(req,res)=>{
//     let sampleListing = new Listing({
//         title: "My New Villa",
//         description: "By the beach",
//         price: "1200",
//         location: "calangute, Goa",
//         countary: "India",
//     });

//     await sampleListing.save();
//     console.log("sample was saved");
//     res.send("successful testing");
// });

// app.use((err,req,res,next)=>{
//     res.send("somthing went wrong")
// }) //ye middlewere kaam nahi kar raha hai 

app.all("*",(req,res,next)=>{
    next(new ExpressError(404,"page not found!"));
})

app.use((err,req,res,next)=>{
    let {statusCode=500, message = "something went wrong"} = err;
    res.status(statusCode).render("error.ejs",{err});
   // res.status(statusCode).send(message);
});

app.listen(8080,()=>{
    console.log("server is listening to port 8080");
});