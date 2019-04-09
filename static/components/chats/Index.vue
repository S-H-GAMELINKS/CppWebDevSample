<template>
    <div class="container" data-controller="room" data-chat-url="/api/talks" data-chat-refresh-interval="100">
        <h1>All Chat Room's</h1>
        <div class="input-group">
            <div class="input-group-append">
                <span class="input-group-text">Create New Chat Room</span>
            </div>
            <input type="text" class="form-control" data-target="room.new"> 
        </div>
        <p>
            <button type="button" class="btn btn-primary" data-action="click->room#submit">Submit</button>
        </p>

        <div data-target="rooms"></div>
    </div>
</template>
